chomp($t=<>);
while($t > 0)
{
    chomp($_=<>);
    @str = split(' ',$_);
    $W = $str[0];
    $B = $str[1];
    
    if($B%2==1){
        print("1.000000\n");}
    else{
        print("0.000000\n");}
    $t -= 1;
}
