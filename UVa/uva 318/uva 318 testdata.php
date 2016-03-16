<?php
for ($i=0; $i < 100; $i++) { 
	$n=10;
	$k=20;
	echo $n." ".$k."\n";
	$arr=array();
	while ($k) {
		$a=rand(1,$n);
		$b=rand(1,$n);
		if($a!=$b&&!isset($arr[$a][$b])){
			echo $a." ".$b." ".rand(20,100)."\n";
			$arr[$a][$b]=true;
			$arr[$b][$a]=true;
			$k--;
		}
	}
	echo "\n";
}
echo "0 0\n";
?>