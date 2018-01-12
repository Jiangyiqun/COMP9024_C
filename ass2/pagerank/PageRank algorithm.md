# PageRank algorithm

```
pagerankList[nV][4] = {url, out degree, PR}

PageRank(web, d, diffPR, maxIterations)
    input: graph web contains URL and their relationship
            damping factor d
            max diffPR
            maxIterations
    output: an array contains all 

    oldPR[nV]
    newPR[nV]
    incomingPR

    For each vertex v in web
        oldPR[v] = 1 / nV
    end For

    iteration = 0;
    diff = diffPR;
    While (iteration < maxIteration AND diff >= diffPR)
        iteration++;

            for each vertex v in web    // calculate newPR[v]
                incomingPR = 0
                for each vertices w in web    // calculate incomingPR for newPR[v]
                    if w is adjacent to v then
                        incomingPR += oldPR[w] / pagerankList[w][2] 
                    end if
                newPR[v] = (1 - d) / nV + d * incomingPR
                end for
            end for

            diff = 0
            for each vertex in web
                diff += abs(newPR[v] - oldPR[v])
            end for

            for each vertex v in the graph 
                oldPR[v] = newPR[v]
            end for
    end While
```