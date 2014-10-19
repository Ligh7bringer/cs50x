<?php
    require("../includes/config.php"); 
    
    $cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
       
	if($_SERVER["REQUEST_METHOD"] == "POST") {
		
        if (empty($_POST["symbol"]))
        {
            apologize("You must enter a symbol.");
        }
        else if (empty($_POST["shares"]))
        {
            apologize("You must enter a number of shares to buy.");
        }
        else if (preg_match("/^\d+$/", $_POST["shares"]) == false)
        {
            apologize("You must enter a valid number of shares to buy.");
        }
        	        	
			if($stock = lookup(strtoupper($_POST["symbol"])) == false) {
				apologize("The symbol was not found.");
			}
				$stock = lookup(strtoupper($_POST["symbol"]));
				$rows = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
				$cash = $rows[0]["cash"];
				$price = $stock["price"];
				$cost = $price * $_POST["shares"];
            
			if($cost > $cash) {
				apologize("You do not have enough money.");
			} else {
				query("UPDATE users set cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);                
                query("INSERT INTO stocks (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $stock["symbol"], $_POST["shares"]);  
				
			    $date = date('Y-m-d H:i:s');
				
				$query = query("INSERT INTO history (user_id, type, symbol, shares, price, date) VALUES(?, 'BUY', ?, ?, ?, ?)", $_SESSION["id"], $stock["symbol"], $_POST["shares"], $stock["price"], $date);
                redirect("index.php");              
			}		
		}	
		
	render("../templates/buy_form.php", ["title" => "Buy"]);
	
    
?>
