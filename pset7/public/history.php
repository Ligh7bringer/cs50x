<?php
	require("../includes/config.php");
	
	$positions = query("SELECT type, symbol, shares, price, date FROM history WHERE user_id = ?", $_SESSION["id"]);	
	render("history_template.php", ["title" => "History", "positions" => $positions]);


?>
