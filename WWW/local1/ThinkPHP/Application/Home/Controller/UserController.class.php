<?php

namespace Home\Controller;
use Think\Controller;

class UserController extends Controller {

    public function login()
    {
        if (IS_POST) {
            $login = D('login');
            if (!$data = $login->create()) {
                header("Content-type: text/html; charset=utf-8");
                exit($login->getError());
            }
            //var_dump($data);
            $where = array();
            $where['username'] = $data['username'];
            $result = $login->where($where)->field('username,password,lastdate,email')->find();
            $data[password]=md5($data[password]);
            if ($result && $result['password'] == $data['password']) {
                session('username', $result['username']);
                M('user')->where($where)->save($data);
                redirect(U('Home/home'));
            } else {
                $this->error('登录失败,用户名或密码不正确!');
            }
        } else {
            $this->error('出错了');
        }
    }

    public function register()
    {
        if (IS_POST) {
            $user = D('register');
            if (!$data = $user->create()) {
                header("Content-type: text/html; charset=utf-8");
                exit($user->getError());
            }
            $data[password]=md5($data[password]);
            if ($id = $user->add($data)) {
                $this->success('注册成功', U('Index/index'), 2);
            } else {
                $this->error('注册失败');
            }
        } else {
            $this->display();
        }
    }

    public function logout()
    {
        header("Content-type:text/html;charset=utf-8");
        session('username',null);
        redirect(U('Index/index'));
    }

    public function verify()
    {
        // 实例化Verify对象
        $verify = new \Think\Verify();

        // 配置验证码参数
        $verify->fontSize = 14;     // 验证码字体大小
        $verify->length = 4;        // 验证码位数
        $verify->imageH = 34;       // 验证码高度
        $verify->useImgBg = false;   // 开启验证码背景
        $verify->useNoise = false;  // 关闭验证码干扰杂点
        $verify->useCurve = false;
        $verify->entry();
    }
}