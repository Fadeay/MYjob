<?php

namespace Home\Controller;
use Think\Controller;

class HomeController extends CommonController {

    public function home(){

        $this->assign('webtitle', 'Home');
        $this->display();
    }
}