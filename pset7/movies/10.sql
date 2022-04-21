SELECT name from people
join directors on people.id = directors.person_id join ratings on directors.movie_id = ratings.movie_id where rating >= 9
group by directors.person_id;