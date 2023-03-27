from pyswip import Prolog

prolog = Prolog()

prolog.assertz("instructor(chan, math273)")
prolog.assertz("instructor(patel, ee222)")
prolog.assertz("instructor(patel, ee222)")

list(prolog.query("father(michael,X)")) == [{'X': 'john'}, {'X': 'gina'}]
for soln in prolog.query("father(X,Y)"):
    print(soln["X"], "is the father of", soln["Y"])