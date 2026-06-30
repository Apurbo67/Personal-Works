COS80021 Project 1
Student: Kazi Nazmus Sakib Apurbo
ID: 105950524

Files in Project01
- config.php    : Database connection and escape function.
- register.php  : Allows a new customer to register (Task 1.2 partial: no email sent).
- login.php     : Existing customer login, checks email and password.
- booking.php   : Customer booking page. Validates inputs, enforces 40 minute rule, 
                  inserts booking, shows confirmation, sends email (Task 2.4 partial: 
                  email only works for Swinburne addresses).
- admin.php     : Staff page to list unassigned bookings (next 2 hours) and assign a booking.
- logout.php    : Ends a customer session and returns to login.
- schema.sql    : SQL file for creating the customer and booking tables.

Database tables:
- customer(email, cust_name, passwd, phone)
- booking(booking_ref, email, passenger_name, passenger_phone, unit_no, street_no,
          street_name, suburb, dest_suburb, pickup_datetime, booking_datetime, status)

Notes:
- Task 1.2 (registration) is partial because registering a new account does not send any email.
- Task 2.4 (confirmation email) is partial because emails only work for Swinburne email 
  accounts. External domains like Gmail do not receive the email most likely to server restrictions.

How to run:
1. Import schema.sql into the database (s105950524_db).
2. Upload PHP files into on Mercury.
3. Test in browser:
   https://mercury.swin.edu.au/cos80021/s105950524/Project1/login.php
