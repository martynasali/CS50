-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT year, name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE "%courthouse%";
 year | name | transcript
 
2020 | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

2020 | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

2020 | Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
The thief then asked the person on the other end of the phone to purchase the flight ticket.


-- 2020 | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
-- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.


SELECT name, phone_number, passport_number, license_plate from people where license_plate in 
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND
day = 28 AND HOUR = 10 AND minute >= 15 and minute <= 25 AND activity = "exit");
-- PARKING LOT LEAVES
-- name | phone_number | passport_number | license_plate
-- Patrick | (725) 555-4692 | 2963008352 | 5P2BI95
-- Amber | (301) 555-4174 | 7526138472 | 6P58WS2
-- Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
-- Roger | (130) 555-0289 | 1695452385 | G412CB7
-- Danielle | (389) 555-5198 | 8496433585 | 4328GD8
-- Russell | (770) 555-1861 | 3592750733 | 322W7JE
-- Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- Ernest | (367) 555-5533 | 5773159633 | 94KL13X

-- 2020 | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
-- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.


 SELECT name, phone_number, passport_number, license_plate from people where id IN
 (SELECT person_id from bank_accounts WHERE account_number IN
 (SELECT account_number FROM atm_transactions 
 WHERE year = 2020 AND month = 7 AND day = 28 
 AND atm_location = "Fifer Street" and transaction_type = "withdraw"));
--  ATM withdraw
--  Bobby | (826) 555-1652 | 9878712108 | 30G67EN
-- Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
-- Victoria | (338) 555-6650 | 9586786673 | 8X428L0
-- Madison | (286) 555-6063 | 1988161715 | 1106N58
-- Roy | (122) 555-4581 | 4408372428 | QX4YZN3
-- Danielle | (389) 555-5198 | 8496433585 | 4328GD8
-- Russell | (770) 555-1861 | 3592750733 | 322W7JE
-- Ernest | (367) 555-5533 | 5773159633 | 94KL13X

-- 2020 | Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- FLIGHT
SELECT id, destination_airport_id, day, hour, minute from flights where year = 2020 AND month = 7 AND day = 29 AND origin_airport_id = 8 ORDER BY hour, minute;
-- 36, 4 | LHR | Heathrow Airport | London

-- PASSENGERS 
SELECT name, phone_number, passport_number, license_plate FROM people WHERE passport_number IN
(SELECT passport_number from passengers WHERE flight_id = 36);

-- name | phone_number | passport_number | license_plate
-- Bobby | (826) 555-1652 | 9878712108 | 30G67EN
-- Roger | (130) 555-0289 | 1695452385 | G412CB7
-- Madison | (286) 555-6063 | 1988161715 | 1106N58
-- Danielle | (389) 555-5198 | 8496433585 | 4328GD8
-- Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- Edward | (328) 555-1152 | 1540955065 | 130LD9Z
-- Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- Doris | (066) 555-9701 | 7214083635 | M51FA04

-- CALLERS
SELECT name, phone_number, passport_number from people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 61);

-- name | phone_number | passport_number
-- Bobby | (826) 555-1652 | 9878712108
-- Roger | (130) 555-0289 | 1695452385
-- Victoria | (338) 555-6650 | 9586786673
-- Madison | (286) 555-6063 | 1988161715
-- Russell | (770) 555-1861 | 3592750733
-- Evelyn | (499) 555-9472 | 8294398571
-- Kathryn | (609) 555-5876 | 6121106406
-- Ernest | (367) 555-5533 | 5773159633
-- Kimberly | (031) 555-6622 | 9628244268

SELECT caller, receiver, duration from phone_calls WHERE year = 2020 AND month = 7 AND day = 28 and caller = "(367) 555-5533" or receiver = "(367) 555-5533";
--         caller | receiver.      | duration
-- (020) 555-6715 | (367) 555-5533 | 414
-- (695) 555-0348 | (367) 555-5533 | 218
-- (367) 555-5533 | (375) 555-8161 | 45
-- (367) 555-5533 | (344) 555-9601 | 120
-- (367) 555-5533 | (022) 555-4052 | 241
-- (367) 555-5533 | (704) 555-5790 | 75




SELECT name from people WHERE phone_number = "(375) 555-8161";
-- sancha pancha Berthold



























