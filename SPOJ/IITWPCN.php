<?php
$read = fopen("php://stdin","r");
$write = fopen("php://stdout","w");

fscanf($read,"%d",$t);
while($t--)
{
    fscanf($read,"%d %d",$W,$B);
    if($B & 1)
        fprintf($write,"1.000000\n");
    else
        fprintf($write,"0.000000\n");
}
fclose($read);
fclose($write);
?>
