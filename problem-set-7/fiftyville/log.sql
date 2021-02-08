-- Keep a log of any SQL queries you execute as you solve the mystery.
Who the thief is,
--This query is formed based on what I learned by exploring each table and studying the transcript of the interviews conducted on the day the theft occurred
--The result from this query is Ernest
SELECT name FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller IN
(SELECT phone_number FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND phone_number IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT DISTINCT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25 AND license_plate IN
(SELECT license_plate FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id =
(SELECT id FROM flights WHERE day = 29 ORDER BY hour ASC LIMIT 1)))))))));

What city the thief escaped to, and
--This query locates the specific city the thief escaped to by matching the destination_airport_id from flights with the id of the airports
--The result from this query is London
SELECT city FROM airports WHERE id =
(SELECT destination_airport_id FROM flights WHERE day = 29 ORDER BY hour ASC LIMIT 1);

Who the thief’s accomplice is who helped them escape
--This query reveals the thief’s accomplice by exchanging the caller with the receiver
--Apart from that, this query is identical to the one used to identify the thief
--The result from this query is Berthold
SELECT name FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller IN
(SELECT phone_number FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Fifer Street" AND phone_number IN
(SELECT phone_number FROM people WHERE license_plate IN
(SELECT DISTINCT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25 AND license_plate IN
(SELECT license_plate FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id =
(SELECT id FROM flights WHERE day = 29 ORDER BY hour ASC LIMIT 1)))))))));
