#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank]=i;
            // printf("rank-eil:%i ranks[i]:%i, i: %i", rank, ranks[rank], i );
            return true;
        }

    }
    // TODO
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    int prog = 1;

    for (int i = candidate_count -1; i > -1; i--)
    {
            int z = i;
        for(int j = 0; j < prog; j++)
        {
            int c = ranks[z];
            int d = ranks[i];
            // preferences[i][j] is number of voters who prefer i over j
            preferences[d][c]  += 1;
            preferences[d][d] = 0;
            // printf("preferences[%i][%i] = %i, i-as: %i\n", d, c, preferences[d][c], i);
            // printf("ranks from last, %i__j:%i \n", ranks[i], j);
            z++;
        }
        prog++;

    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
   int c = 0;
    for (int i = 0; i < candidate_count; i++)
    {
       for (int j = 0; j < candidate_count; j++)
       {
               if (preferences[i][j] > 0 && preferences[i][j] > preferences[j][i] )
               {
            //   printf("preferences[%i][%i]: %i\n", i, j, preferences[i][j]);
               pairs[c].winner = i;
               pairs[c].loser = j;
            //   printf("winner: %i\n", pairs[c].winner);
            //   printf("loser: %i\n", pairs[c].loser);
               c++;
               }
       }
    }
    pair_count = c;
    // printf("pair_count: %i\n", pair_count);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    for (int i = 0; i < pair_count; i++)
    {  int a = 0; int js = 0;
        for (int j = 0; j < pair_count; j++)
        {
            if(preferences[pairs[j].winner][pairs[j].loser]-preferences[pairs[j].loser][pairs[j].winner] > a)
            {
                a = preferences[pairs[j].winner][pairs[j].loser]-preferences[pairs[j].loser][pairs[j].winner];
                // printf("a: %i js: %i\n", a, js);
                js = j;


            }

        }
        int laik = pairs[i].winner;
        pairs[i].winner = pairs[js].winner;
        pairs[js].winner = laik;
        laik = pairs[i].loser;
        pairs[i].loser = pairs[js].loser;
        pairs[js].loser = laik;

        preferences[pairs[i].winner][pairs[i].loser] = 0;
        preferences[pairs[i].loser][pairs[i].winner] = 0;


    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
int win[pair_count];
int lose[pair_count];

    for (int x = 0; x < pair_count; x++)
    {
        win[x] = pairs[x].winner;
        lose[x] = pairs[x].loser;
        // printf("win[%i]lose[%i]\n", pairs[x].winner, pairs[x].loser);
        locked[win[x]][lose[x]] = true;
    }

// ----------------------------------------------------------------
int zx = 0;


   for (int i = 1; i < pair_count; i++)
   {
       for(int j = 0; j < i; j++)
       {
            if(win[i] == lose[j] )
            {
                 for(int c = 0; c < i; c++)
                 {
                    if(lose[i] == win[c])
                    {
                        for(int z = 0; z < i; z++)
                        {
                            if(locked[lose[i]][win[z]] == true)
                            {
                            zx++;
                            if(zx >= 1)
                            {
                            locked[win[i]][lose[i]] = false;
                            // printf("locked[win[%i][lose[%i]] = %d \n", win[i], lose[i], locked[win[i]][lose[i]]);
                            }
                            }
                        }
                    }
                 }
            }
        }
   }
   return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int falseCan = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if(locked[j][i] == false)
            {
                falseCan++;
                if(falseCan == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
}

