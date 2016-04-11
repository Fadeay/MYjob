<?php

namespace Admin___\Controller;
use Think\Controller;

class HomeController extends CommonController {
    public function home(){
        //$info = M('user')->field('username')->where(array('username' => parent::$user))->find();

        //$this->assign('info', $this->user);
        $this->display();
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
                $this->success('添加成功', U('Index/index'), 2);
            } else {
                $this->error('添加失败');
            }
        } else {
            $this->display();
        }
    }
}