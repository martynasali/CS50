


SELECT id, description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";

-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. 
-- Interviews were conducted today with three witnesses who were present at the time 
-- — each of their interview transcripts mentions the courthouse.

SELECT year, name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE "%courthouse%";
 year | name | transcript
 
2020 | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

2020 | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

2020 | Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
The thief then asked the person on the other end of the phone to purchase the flight ticket.
 
 
 
 

-- 2020 | Sometime within ten minutes of the theft, 
-- I saw the thief get into a car in the courthouse parking lot and drive away. 
-- If you have security footage from the courthouse parking lot, 
-- you might want to look for cars that left the parking lot in that time frame.

SELECT activity, license_plate FROM courthouse_security_logs WHERE year = 2020 and month = 7 AND day = 28
AND hour = 10 AND minute < 25 AND minute > 15;
-- exit | 5P2BI95
-- exit | 94KL13X
-- exit | 6P58WS2
-- exit | 4328GD8
-- exit | G412CB7
-- exit | L93JTIZ
-- exit | 322W7JE
-- exit | 0NTHK55

-- name | passport_number
-- Patrick | 2963008352
-- Amber | 7526138472
-- Elizabeth | 7049073643

-- !!Roger | 1695452385

-- !!Danielle | 8496433585
-- Russell | 3592750733
-- !!Evelyn | 8294398571
-- !!Ernest | 5773159633
-- Sophia | 3642612721


-- 7214083635 | Doris | (066) 555-9701
-- 1695452385 | !!Roger | (130) 555-0289
-- 5773159633 | !!Ernest | (367) 555-5533
-- 1540955065 | Edward | (328) 555-1152
-- 8294398571 | Evelyn | (499) 555-9472
-- 1988161715 | Madison | (286) 555-6063
-- 9878712108 | Bobby | (826) 555-1652
-- 8496433585 | Danielle | (389) 555-5198

-- caller         | receiver       | duration
-- (130) 555-0289 | (996) 555-8899 | 51!!
-- (499) 555-9472 | (892) 555-8872 | 36
-- (367) 555-5533 | (375) 555-8161 | 45!!
-- (609) 555-5876 | (389) 555-5198 | 60
-- (499) 555-9472 | (717) 555-1342 | 50
-- (286) 555-6063 | (676) 555-6554 | 43
-- (770) 555-1861 | (725) 555-3243 | 49
-- (031) 555-6622 | (910) 555-3251 | 38
-- (826) 555-1652 | (066) 555-9701 | 55
-- (338) 555-6650 | (704) 555-2131 | 54



(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 and month = 7 AND day = 28
AND hour = 10 AND minute < 25 AND minute > 15);


-- 2020 | I don't know the thief's name, but it was someone I recognized. 
-- Earlier this morning, before I arrived at the courthouse, 
-- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

SELECT account_number, transaction_type, amount FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" and transaction_type = "withdraw";
-- 28500762 | withdraw | 48                                                                                              
-- 28296815 | withdraw | 20                                                                                              
-- 76054385 | withdraw | 60                                                                                              
-- 49610011 | withdraw | 50                                                                                              
-- 16153065 | withdraw | 80                                                                                              
-- 86363979 | deposit | 10                                                                                               
-- 25506511 | withdraw | 20                                                                                              
-- 81061156 | withdraw | 30                                                                                              
-- 26013199 | withdraw | 35 
SELECT name, phone_number, passport_number FROM people where id IN
(SELECT person_id FROM bank_accounts where account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" and transaction_type = "withdraw"));
-- name | phone_number | passport_number
-- Bobby | (826) 555-1652 | 9878712108
-- Elizabeth | (829) 555-5269 | 7049073643
-- Victoria | (338) 555-6650 | 9586786673
-- Madison | (286) 555-6063 | 1988161715
-- Roy | (122) 555-4581 | 4408372428
-- Danielle | (389) 555-5198 | 8496433585
-- Russell | (770) 555-1861 | 3592750733
-- Ernest | (367) 555-5533 | 5773159633

-- caller         | receiver       | duration
-- (130) 555-0289 | (996) 555-8899 | 51
-- (499) 555-9472 | (892) 555-8872 | 36
-- (367) 555-5533 | (375) 555-8161 | 45
-- (609) 555-5876 | (389) 555-5198 | 60
-- (499) 555-9472 | (717) 555-1342 | 50
-- (286) 555-6063 | (676) 555-6554 | 43
-- (770) 555-1861 | (725) 555-3243 | 49
-- (031) 555-6622 | (910) 555-3251 | 38
-- (826) 555-1652 | (066) 555-9701 | 55
-- (338) 555-6650 | (704) 555-2131 | 54



-- 2020 | As the thief was leaving the courthouse, 
-- they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest 
-- flight out of Fiftyville tomorrow. The thief then asked the person on the other
-- end of the phone to purchase the flight ticket.

SELECT flights.id, destination_airport_id, origin_airport_id, hour, minute FROM flights 
JOIN airports ON flights.origin_airport_id = airports.id WHERE city = "Fiftyville" and flights.year = 2020 AND flights.month = 7 AND flights.day = 29;

-- id | destination_airport_id | origin_airport_id | hour | minute
-- 18 |         6              |         8.        |  16  |   0
-- 23 |         11             |         8         |  12  |   15
-- EARLYEST LONDON
-- 36 |         4              |         8         |   8  |   20

-- 43 |         1              |         8         |   9  |   30
-- 53 |         9              |         8         |   15 |   20

SELECT * from airports
-- 1 | ORD | O'Hare International Airport | Chicago
-- 2 | PEK | Beijing Capital International Airport | Beijing
-- 3 | LAX | Los Angeles International Airport | Los Angeles

-- ID NO 4
-- 4 | LHR | Heathrow Airport | London

-- 5 | DFS | Dallas/Fort Worth International Airport | Dallas
-- 6 | BOS | Logan International Airport | Boston
-- 7 | DXB | Dubai International Airport | Dubai
-- 8 | CSF | Fiftyville Regional Airport | Fiftyville
-- 9 | HND | Tokyo International Airport | Tokyo
-- 10 | CDG | Charles de Gaulle Airport | Paris
-- 11 | SFO | San Francisco International Airport | San Francisco
-- 12 | DEL | Indira Gandhi International Airport | Delhi

SELECT passengers.passport_number,  name, phone_number FROM passengers
JOIN people on people.passport_number = passengers.passport_number where flight_id = 36;



-- 7214083635 | Doris | (066) 555-9701
-- 1695452385 | Roger | (130) 555-0289
-- 5773159633 | Ernest | (367) 555-5533
-- 1540955065 | Edward | (328) 555-1152
-- 8294398571 | Evelyn | (499) 555-9472
-- 1988161715 | Madison | (286) 555-6063
-- 9878712108 | Bobby | (826) 555-1652
-- 8496433585 | Danielle | (389) 555-5198


SELECT caller, receiver, duration FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 61;
-- caller         | receiver       | duration
-- (130) 555-0289 | (996) 555-8899 | 51
-- (499) 555-9472 | (892) 555-8872 | 36
-- (367) 555-5533 | (375) 555-8161 | 45
-- (609) 555-5876 | (389) 555-5198 | 60
-- (499) 555-9472 | (717) 555-1342 | 50
-- (286) 555-6063 | (676) 555-6554 | 43
-- (770) 555-1861 | (725) 555-3243 | 49
-- (031) 555-6622 | (910) 555-3251 | 38
-- (826) 555-1652 | (066) 555-9701 | 55
-- (338) 555-6650 | (704) 555-2131 | 54

-- caller            | receiver       | duration
-- -- (130) 555-0289 | (996) 555-8899 | 51

-- 1695452385 | Roger | (130) 555-0289

SELECT name, passport_number, license_plate FROM people WHERE phone_number = "(996) 555-8899";
-- name | passport_number | license_plate
-- Jack | 9029462229 | 52R0Y8U


SELECT account_number, transaction_type, amount FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street";

SELECT name, passport_number FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 and month = 7 AND day = 28
AND hour = 10 AND minute < 30 AND minute > 10);

-- name | passport_number
-- Patrick | 2963008352
-- Amber | 7526138472
-- Elizabeth | 7049073643

-- ROGERS CAR
-- Roger | 1695452385

-- Danielle | 8496433585
-- Russell | 3592750733
-- Evelyn | 8294398571
-- Ernest | 5773159633
-- Sophia | 3642612721

SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" and transaction_type = "withdraw");

-- person_id
-- 686048
-- 514354
-- 458378
-- 395717
-- 396669
-- 467400
-- 449774
-- 438727

SELECT name, phone_number, license_plate FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" and transaction_type = "withdraw"));

-- name | phone_number.   | license_plate
-- Bobby | (826) 555-1652 | 30G67EN
-- Elizabeth | (829) 555-5269 | L93JTIZ
-- Victoria | (338) 555-6650 | 8X428L0
-- Madison | (286) 555-6063 | 1106N58
-- Roy | (122) 555-4581 | QX4YZN3
-- Danielle | (389) 555-5198 | 4328GD8
-- Russell | (770) 555-1861 | 322W7JE
-- Ernest | (367) 555-5533 | 94KL13X

-- (367) 555-5533 | (113) 555-7544
-- (020) 555-6715 | (367) 555-5533
-- (367) 555-5533 | (238) 555-5554
-- (367) 555-5533 | (660) 555-3095
-- (367) 555-5533 | (286) 555-0131
-- (695) 555-0348 | (367) 555-5533
-- (367) 555-5533 | (375) 555-8161
-- (367) 555-5533 | (344) 555-9601
-- (367) 555-5533 | (022) 555-4052
-- (367) 555-5533 | (704) 555-5790
-- (367) 555-5533 | (455) 555-5315
-- (367) 555-5533 | (841) 555-3728
-- (367) 555-5533 | (696) 555-9195


-- exit | 5P2BI95
-- exit | 94KL13X
-- exit | 6P58WS2
-- exit | 4328GD8
-- exit | G412CB7
-- exit | L93JTIZ
-- exit | 322W7JE
-- exit | 0NTHK55
SELECT caller, receiver FROM phone_calls WHERE caller = "(130) 555-0289" OR receiver = "(130) 555-0289";

SELECT caller, receiver FROM phone_calls WHERE caller = "(367) 555-5533" OR receiver = "(367) 555-5533";

-- (130) 555-0289 | (730) 555-5115
-- (491) 555-2505 | (130) 555-0289
-- (130) 555-0289 | (042) 555-1772
-- (130) 555-0289 | (996) 555-8899
-- (821) 555-5262 | (130) 555-0289
-- (258) 555-5627 | (130) 555-0289
-- (130) 555-0289 | (427) 555-0556