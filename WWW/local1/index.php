<!DOCTYPE html>
<html lang="zh-cn">
<head>
<meta name="viewport" content="width=device-width, initial-scale=1,
maximum-scale=1, user-scalable=no">
<title>Home</title>
<link rel="stylesheet" href="/bootstrap/dist/css/bootstrap.min.css">
</head>
<body style="background-color: grey">
<br/><br/><br/>
  <div class="col-md-2">
  <hr>
            <?php
                $rootname = dirname(__FILE__);
                $dir = dir($rootname);
                while (($file = $dir->read()) !== false){
                    if($file == '.' or
                        $file == '..' or
                        $file == 'bootstrap'or
                        $file == 'index.php'){
                        continue;
                    }
echo <<<end
                    <a href='$file' >
                        <blockquote class="text-success">
                         $file
                        </blockquote>
                    </a>
                    <hr>
end;
                }
            ?>
  </div>
<script src="/bootstrap/js/tests/vendor/jquery.min.js"></script>
<script src="/bootstrap/dist/js/bootstrap.min.js"></script>
</body>
</html>