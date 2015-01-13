select Score, Rank
    from
        (select Score, if(Score=@prev, @rank, @rank:=@rank+1) as Rank, @prev:=Score
            from
                (select Score
                    from Scores
                    order by Score desc) as t0,
                (select @rank:=0) as t1,
                (select @prev:=NULL) as t2) as t
