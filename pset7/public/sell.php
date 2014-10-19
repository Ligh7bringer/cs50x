<?php
require("../includes/config.php");

if($_SERVER["REQUEST_METHOD"] == "POST") {
	if(empty($_POST["symbol"])) {
		apologize("You must select stocks to sell.");
	} 
	
	$temp = lookup($_POST["symbol"]);
	$positions = query("SELECT * FROM stocks WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
                
    query("DELETE FROM stocks WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
    
    $credit = $temp["price"] * $positions[0]["shares"];
    query("UPDATE users set cash = cash + ? WHERE id = ?", $credit, $_SESSION["id"]);
    
    $date = date('Y-m-d H:i:s');	
	query("INSERT INTO history (user_id, type, symbol, shares, price, date) VALUES(?, 'SELL', ?, ?, ?, ?)", $_SESSION["id"], $temp["symbol"], $positions[0]["shares"], $temp["price"], $date);
	
	redirect("index.php");

} else {
	$positions = query("SELECT * FROM stocks WHERE id = ?", $_SESSION["id"]);
    render("sell_form.php", ["title" => "Sell", "positions" => $positions]);
}

?>
