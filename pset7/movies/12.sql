select distinct title from movies where title in
(select DISTINCT title from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where people.name='Johnny Depp' or people.name='Helena Bonham Carter' group by movies.title having count(*) = 2);
