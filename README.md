# fdrcontrol

The **fdrcontrol** package tends replace *p.adjust(method='BH') or p.adjust(method='fdr')* for a faster filtering step.

The *FDRcontrol* function takes in a vector of p-values and an alpha value (threshold) for controlling false discovery rate. The algorithm used was described in [here]( https://www.urmc.rochester.edu/biostat/people/faculty/TuSite/FDR_procedure.pdf).

The function return 1 when the datapoint is below the threshold and 0 if it is above the threshold.

To install:

```
devtools::install_github('wckdouglas/fdrcontrol')
```
