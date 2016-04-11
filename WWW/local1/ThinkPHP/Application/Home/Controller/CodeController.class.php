<?php

namespace Home\Controller;
use Think\Controller;

class CodeController extends CommonController {

    public function base64(){

        $this->assign('origin','');
        if (IS_POST) {
            $postdata = htmlspecialchars($_POST['base64']);
            $this->assign('origin',$postdata);
            if ($_POST['way']=="encode") {
                $data = array('cmd'=>'enbase64','msg' => array('msg'=>$postdata));
                $this->assign('anwser',mysocket($data));
            } else if($_POST['way']=="decode") {
                $data = array('cmd'=>'debase64','msg' => array('msg'=>$postdata));
                $this->assign('anwser',mysocket($data));
            }
        }
        $this->assign('webtitle', 'Base64');
        $this->display();
    }

    public function url(){
        $this->assign('origin','');
        if (IS_POST) {
            $postdata = htmlspecialchars($_POST['input']);
            $this->assign('origin',$postdata);
            if ($_POST['way']=="encode") {
                $data = array('cmd'=>'enurl','msg' => array('msg'=>$postdata));
                $this->assign('anwser',mysocket($data));
            } else if($_POST['way']=="decode") {
                $data = array('cmd'=>'deurl','msg' => array('msg'=>$postdata));
                $this->assign('anwser',mysocket($data));
            }
        }
        $this->assign('webtitle', 'Url编码');
        $this->display();
    }

    public function radix(){
        $this->assign('origin','');
        if (IS_POST) {
            $postdata = htmlspecialchars($_POST['input']);
            $option1 = $_POST['option1'];
            $option2 = $_POST['option2'];
            $this->assign('origin',$postdata);
            $data = array('cmd'=>$option1.$option2,'msg' => array('msg'=>$postdata));
            $this->assign('anwser',mysocket($data));
        }
        $this->assign('webtitle', '进制转换');

        $this->display();
    }

    public function md5(){
        $this->assign('origin','');
        if (IS_POST) {
            $postdata = htmlspecialchars($_POST['input']);
            $this->assign('origin',$postdata);
            $data = array('cmd'=>'md5md5','msg' => array('msg'=>$postdata));
            $md5md5 = mysocket($data);
            $this->assign('md532',substr($md5md5,0,32));
            $this->assign('md516',substr($md5md5,32));
        }
        $this->assign('webtitle', 'MD5');
        $this->display();
    }


}