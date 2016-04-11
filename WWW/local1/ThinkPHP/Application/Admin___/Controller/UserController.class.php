<?php

namespace Admin___\Controller;
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
            //var_dump($_POST);
            //var_dump($data);
            $where = array();
            $where['username'] = $data['adminname'];
            $result = $login->where($where)->field('adminname,password,lastdate,lastip')->find();
            $data[password]=md5($data[password]);
            if ($result && $result['password'] == $data['password']) {
                session('adminname', $result['adminname']);
                M('user')->where($where)->save($data);

                redirect(U('Home/home'));
            } else {
                $this->error('登录失败,用户名或密码不正确!');
            }
        } else {
            $this->error('出错了');
        }
    }

    public function logout()
    {
        header("Content-type:text/html;charset=utf-8");
        session('adminname',null);
        redirect(U('Index/index'));
    }
}