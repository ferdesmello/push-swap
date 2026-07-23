from generators import exact_disorder_permutation
from disorder import compute_disorder

for d in [0.0,0.2,0.4,0.6,0.8,1.0]:

    p = exact_disorder_permutation(20,d)

    print(d, compute_disorder(p))