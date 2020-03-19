<?php
	$s = fgets(STDIN);
	$arr = count_chars($s);
	echo min($arr[ord("c")], $arr[ord("a")], $arr[ord("t")])."\n";
	$max = max($arr[ord("c")], $arr[ord("a")], $arr[ord("t")]);
	echo ($max - $arr[ord("c")])."\n";
	echo ($max - $arr[ord("a")])."\n";
	echo ($max - $arr[ord("t")])."\n";
?>
