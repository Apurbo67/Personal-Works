COS80021 Project 2
Student: Kazi Nazmus Sakib Apurbo
ID: 105950524

Key files & endpoints

Frontend pages (UI)

home.htm — Home/welcome page

listing.htm — Form/UI to create new listings (calls server to create an entry)

bidding.php — Bidding UI (card layout / Place Bid / Buy It Now)

maintenance.htm (or maintenance.php) — Maintenance UI (Process & Report)

login.htm, register.htm — auth pages

Javascript

listing.js — listing page JS (AJAX to create listings / load categories)

bidding_new.js — bidding UI JS (loads feed, Place Bid / Buy It Now logic)

maintenance.js — maintenance UI JS (process / report actions)

Server-side (PHP)

listing_feed.php — JSON feed of active auctions (used by bidding and listing)

listing.php / listing_action.php — create a new listing endpoint (depends on your setup)

bidding_action.php — handles Place Bid POST requests (validates and updates XML)

buy_action.php — handles Buy It Now POST requests (marks item SOLD)

maintenance_action.php — Process expired items & generate report

logout.php, login.php, register.php — session management

Data files

Primary data folder: /home/students/accounts/s105950524/cos80021/www/data/

auction.xml — auctions data (primary)

customer.xml — registered customers

Note: 
1. The UI refreshing after creating a new listing is not working.
2. Email is not reaching the swinburne mail but works with gmail.

To run: https://mercury.swin.edu.au/cos80021/s105950524/Project2/login.htm