/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-22-21.41
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

void dfs(int v, vector<vector<int> > &g, vector<int> &color) {
    for (int to: g[v]) {
        if (color[to] == 0) {
            color[to] = 4 - color[v];
            dfs(to, g, color);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    vector<vector<int> > G(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d\n", &x, &y);
        --x, --y;
        G[x][y] = G[y][x] = 1;
    }
    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (G[i][j] == 0) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector<int> color(n);
    for (int i = 0; i < n; ++i) {
        if (color[i] != 0) {
            continue;
        }
        if (g[i].empty()) {
            color[i] = 2;
            continue;
        }
        color[i] = 1;
        dfs(i, g, color);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (G[i][j] && min(color[i], color[j]) == 1 && max(color[j], color[i]) == 3) {
                printf("No\n");
                return 0;
            }
            if (G[i][j]) {
                continue;
            }
            if (min(color[i], color[j]) != 1 || max(color[i], color[j]) != 3) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for (int i = 0; i < n; ++i) {
        if (color[i] == 1) {
            printf("a");
        } else if (color[i] == 2) {
            printf("b");
        } else {
            printf("c");
        }
    }
    printf("\n");
    return 0;
}


/*

Test: #1, time: 0 ms., memory: 2020 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
2 1
1 2
Output
Yes
bb
Answer
Yes
aa
Checker Log
ok Participant found valid solution.
Test: #2, time: 15 ms., memory: 2024 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
4 3
1 2
1 3
1 4
Output
No
Answer
No
Checker Log
ok No solution exists.
Test: #3, time: 15 ms., memory: 2012 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
4 4
1 2
1 3
1 4
3 4
Output
Yes
bacc
Answer
Yes
bacc
Checker Log
ok Participant found valid solution.
Test: #4, time: 15 ms., memory: 2016 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
1 0
Output
Yes
b
Answer
Yes
a
Checker Log
ok Participant found valid solution.
Test: #5, time: 0 ms., memory: 2016 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
15 95
1 11
13 7
12 10
1 14
15 14
15 7
13 14
9 10
5 10
7 4
6 13
2 11
14 10
11 4
15 8
11 9
13 15
8 2
2 5
15 4
7 14
12 2
12 9
2 4
1 8
8 3
1 5
1 3
1 10
9 3
6 1
7 2
1 4
7 3
7 10
13 8
8 14
8 9
14 11
6 11
6 12
12 5
14 5
6 7
8 4
2 3
7 8
11 3
1 9
15 11
14 3
8 5
12 11
13 2
15 2
11 5
8 10
11 10
12 7
14 9
13 11
8 11
5 3
7 11
3 4
1 7
1 15
12 14
15 5
7 5
2 10
7 9
9 4
5 4
13 1
2 9
15 10
13 12
15 3
1 12
10 4
14 2
9 5
6 15
12 4
15 12
10 ...
Output
Yes
bbaaacbbaabbcbb
Answer
Yes
bbaaacbbaabbcbb
Checker Log
ok Participant found valid solution.
Test: #6, time: 15 ms., memory: 2020 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
8 28
3 2
4 2
7 4
6 3
3 7
8 1
3 4
5 1
6 5
5 3
7 1
5 8
5 4
6 1
6 4
2 1
4 1
8 2
7 2
6 8
8 4
6 7
3 1
7 8
3 8
5 7
5 2
6 2
Output
Yes
bbbbbbbb
Answer
Yes
aaaaaaaa
Checker Log
ok Participant found valid solution.
Test: #7, time: 31 ms., memory: 3328 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
417 43540
187 191
81 388
332 273
167 89
99 394
357 385
405 218
127 252
19 282
12 385
329 365
75 235
19 390
368 354
39 321
368 295
143 406
403 187
64 78
360 357
340 345
312 307
323 206
181 258
228 210
293 244
186 15
50 46
47 79
381 170
365 212
57 48
62 260
185 123
325 404
77 149
106 153
250 201
238 190
221 128
39 312
282 94
113 340
237 317
330 138
331 255
281 309
223 144
379 209
41 187
50 396
103 275
184 6
112 225
160 416
403 20
262 240
247 24
262 2...
Output
No
Answer
No
Checker Log
ok No solution exists.
Test: #8, time: 46 ms., memory: 3064 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
500 124750
3 470
57 482
422 366
282 337
185 467
322 55
250 111
172 389
427 146
404 135
443 161
259 10
394 111
192 48
444 8
114 228
277 42
116 139
417 441
263 16
132 328
332 58
94 305
199 416
413 338
489 125
66 98
125 294
39 36
444 430
78 194
413 395
177 338
419 134
337 420
399 148
442 321
97 482
281 443
388 3
289 56
293 394
173 371
282 401
437 363
82 209
140 234
228 251
239 57
172 310
227 49
256 234
221 19
475 293
167 444
295 138
247 353
368 38
221...
Output
Yes
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
Answer
Yes
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Checker Log
ok Participant found valid solution.
Test: #9, time: 30 ms., memory: 4428 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
500 8538
55 35
492 402
492 81
135 387
354 185
288 444
209 68
302 282
155 130
276 423
419 199
483 303
213 43
175 180
336 400
318 133
483 208
445 260
389 396
4 460
245 100
1 335
331 428
197 433
464 349
74 114
268 311
160 156
139 165
83 359
115 143
138 410
144 455
193 333
348 430
236 363
468 312
468 437
456 20
422 253
398 491
271 275
365 487
353 154
443 41
58 369
382 321
21 100
177 193
292 500
131 162
260 258
281 448
129 367
20 167
191 187
45 306
400 3...
Output
No
Answer
No
Checker Log
ok No solution exists.
Test: #10, time: 0 ms., memory: 2028 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
8 28
3 2
4 2
7 4
6 3
3 7
8 1
3 4
5 1
6 5
5 3
7 1
5 8
5 4
6 1
6 4
2 1
4 1
8 2
7 2
6 8
8 4
6 7
3 1
7 8
3 8
5 7
5 2
6 2
Output
Yes
bbbbbbbb
Answer
Yes
aaaaaaaa
Checker Log
ok Participant found valid solution.
Test: #11, time: 15 ms., memory: 2032 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
19 144
5 12
14 12
1 3
4 5
9 14
5 13
2 19
13 15
8 15
6 17
14 13
3 10
19 8
8 13
6 16
16 13
16 17
5 14
5 17
14 18
4 16
13 12
7 2
11 7
19 12
1 13
9 13
7 17
4 19
9 18
17 14
2 5
19 13
16 12
5 8
15 12
17 15
16 1
10 13
7 16
1 10
2 16
5 10
6 10
6 15
4 6
6 18
17 18
2 18
5 3
5 19
16 8
7 6
6 8
8 12
16 10
7 19
3 18
8 3
5 15
12 18
16 18
19 3
11 17
3 13
2 3
11 5
9 2
1 12
19 15
2 1
2 17
3 14
6 19
9 16
4 2
11 19
19 18
16 15
1 14
6 12
2 12
19...
Output
Yes
abacbbcabacaaaabbab
Answer
Yes
abacbbcabacaaaabbab
Checker Log
ok Participant found valid solution.
Test: #12, time: 15 ms., memory: 2032 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
31 417
4 26
29 3
15 7
22 24
22 30
29 24
9 2
10 11
16 19
10 12
9 1
26 24
27 4
13 17
21 2
9 21
16 21
21 11
5 30
31 29
31 20
5 20
25 29
23 11
28 8
23 4
5 3
26 19
3 2
31 2
13 1
18 19
29 19
15 23
9 6
7 22
1 24
9 27
10 2
11 1
9 22
6 3
14 27
23 20
23 26
10 21
11 26
1 19
8 16
4 17
3 19
22 11
10 7
6 20
25 31
9 3
9 4
14 5
28 7
21 26
31 18
7 24
16 20
28 25
28 21
8 6
27 24
23 3
28 23
20 4
22 4
20 18
29 23
1 2
10 5
16 13
14 3
28 15
8 15
14 ...
Output
Yes
aaaabbbcbbabbbcbaaaabbbacabcbab
Answer
Yes
aaaabbbcbbabbbcbaaaabbbacabcbab
Checker Log
ok Participant found valid solution.
Test: #13, time: 0 ms., memory: 2188 KB, exit code: 0, checker exit code: 0, verdict: OK
Input
138 6413
45 35
18 106
107 130
137 127
63 104
21 29
87 82
103 68
120 92
63 94
40 52
132 35
18 136
107 19
88 14
93 56
12 14
108 126
45 117
25 128
65 72
44 82
101 72
131 8
124 11
68 127
105 56
34 69
81 96
32 34
133 32
44 132
29 115
119 58
126 75
125 83
107 135
6 129
82 36
13 100
133 1
126 1
9 36
80 54
16 34
137 54
41 92
35 127
47 41
33 127
25 58
67 73
57 106
48 83
135 71
114 107
67 52
18 7
122 72
127 85
1 127
120 6
134 69
126 82
28 9
63 121
28...
Output
Yes
abacccccaabaabaaabbaaacacbaababaaaabcacbbcaaaaacaaccbacacccaaaaaacbabcaacabcccaaaacacaaacbacaaaaaacaaaaaacaaacaaaaccabccaaabcabccacaaaabaa
Answer
Yes
abacccccaabaabaaabbaaacacbaababaaaabcacbbcaaaaacaaccbacacccaaaaaacbabcaacabcccaaaacacaaacbacaaaaaacaaaaaacaaacaaaaccabccaaabcabccacaaaabaa
Checker Log
ok Participant found valid solution.


*/
