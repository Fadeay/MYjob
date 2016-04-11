<?php

function verify_check($code, $id='')
{
    // 实例化验证码类
    $verify = new \Think\Verify();
    return $verify->check($code, $id);
}

function mysocket($msg){
    set_time_limit(0);
    $port = 51122;
    $ip = "127.0.0.1";
    $msg['token'] = "7654123";
    $data = json_encode($msg);
    $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP) or die("create failed");
    $result = socket_connect($socket, $ip, $port) or die("connect failed");
    socket_write($socket, $data, strlen($data)) or die("write failed");
    $out = socket_read($socket, 1024);
    socket_close($socket);
    return $out;
}
