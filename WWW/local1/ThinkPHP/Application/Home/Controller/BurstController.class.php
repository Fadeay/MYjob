<?php

namespace Home\Controller;
use Think\Controller;

class BurstController extends CommonController {

    public function burstback(){

        $this->assign('webtitle', '后台爆破');
        $data = array('cmd'=>'backdict','msg' => array());
        $file_name = mysocket($data);
        $file_name = iconv('GB2312','UTF-8',$file_name);
        $file_name = explode(':',$file_name,-1);
        foreach ($file_name as $value) {
                $backlist1 .= "<option value ={$value}>{$value}</option>";
            }
        $this->assign('origin',$backlist1);
        $this->display();
    }

    public function startburst(){

        $postdata = htmlspecialchars($_GET['url']);
        $data = array('cmd'=>'burstback','msg' => array('theurl'=>$_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"],'url'=>$postdata,'dict'=>$_GET['dict']));
        $this->ajaxReturn(mysocket($data));
    }
}