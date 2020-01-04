<?php
for($i=10000000; $i<=99999999; $i++) {
    $hash = $i."salt_for_you";
    for($j=0; $j<500; $j++) {
        $hash = sha1($hash);
    }

    if($hash == "a95cdaece4215a46f711d889f5375b01824d3ce1") {
        echo $i;
    }

}
?>