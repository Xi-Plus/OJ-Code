<?php
$n=rand(1000,1000);
echo $n."\n";
for ($i=0; $i < $n; $i++) { 
	echo rand(1,20)." ";
}
echo "\n";
$k=rand(1000,1000);
echo $k."\n";
for ($i=0; $i < $k; $i++) { 
	$c=rand(1,6);
	if($c==1){
		echo "ADD ";
		$s=rand(1,$n);
		echo $s." ";
		$e=rand($s,$n);
		echo $e." ".rand(1,5)."\n";
	}else if($c==2){
		echo "REVERSE ";
		$s=rand(1,$n);
		echo $s." ";
		$e=rand($s,$n);
		echo $e."\n";
	}else if($c==3){
		echo "REVOLVE ";
		$s=rand(1,$n);
		echo $s." ";
		$e=rand($s,$n);
		echo $e." ".rand(1,100)."\n";
	}else if($c==4){
		echo "INSERT ";
		$s=rand(1,$n);
		echo $s." ".rand(1,100)."\n";
		$n++;
	}else if($c==5){
		echo "DELETE ";
		echo rand(1,$n)."\n";
		$n--;
	}else if($c==6){
		echo "MIN ";
		$s=rand(1,$n);
		echo $s." ";
		$e=rand($s,$n);
		echo $e."\n";
	}
}
?>