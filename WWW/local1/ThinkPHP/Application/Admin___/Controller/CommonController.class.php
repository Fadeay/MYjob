<?php

namespace Admin___\Controller;
use Think\Controller;

class CommonController extends Controller {
    public static $user = '';

    public function _initialize()
    {
        if (session('adminname')) {
            $this->user = session('adminname');
        } else {
            $this->error('对不起,您还没有登录,正跳转至登录面...', U('Index/index'));
        }
    }

}