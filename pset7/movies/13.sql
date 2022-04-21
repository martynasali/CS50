SELECT name FROM people where people.id in
(SELECT person_id from stars WHERE movie_id in
(SELECT movie_id from stars WHERE person_id = (SELECT id FROM people WHERE name ='Kevin Bacon' AND birth = 1958))) and people.name != 'Kevin Bacon';