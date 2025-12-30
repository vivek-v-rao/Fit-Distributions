# Fit-Distributions
Fit continuous probability distributions (normal, Laplace, hyperbolic secant, logistic, Student t dof=3, Student t dof=6, generalized error with power of 1.5, symmetric hyperbolic) to data simulated from those distributions. Sample output from `make -f Makefile.gcc` and running the executable is

```
Seed: 17178408637302753969
Groups: 5

Dataset: Normal(mu=0.5, sigma=1.2) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.484          1.195          2.842
Normal                   -1597.36          0.484          1.195          3.000
Laplace                  -1659.18          0.472          1.367          6.000
Hyperbolic Sech          -1630.69          0.484          1.195          5.000
Logistic                 -1613.17          0.484          1.195          4.200
t_3                      -1713.83          0.484          1.195            inf
t_6                      -1620.38          0.484          1.195          3.000
GED_1.5                  -1612.07          0.484          1.195          3.762
SymHyperbolic            -1645.15          0.484          1.195          4.491
Ranking: Normal, GED_1.5, Logistic, t_6, Hyperbolic Sech, SymHyperbolic, Laplace, t_3

Dataset: Normal(mu=0.5, sigma=1.2) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.511          1.181          3.020
Normal                   -1585.10          0.511          1.181          3.000
Laplace                  -1621.71          0.539          1.317          6.000
Hyperbolic Sech          -1604.19          0.511          1.181          5.000
Logistic                 -1593.19          0.511          1.181          4.200
t_3                      -1674.87          0.511          1.181            inf
t_6                      -1599.34          0.511          1.181          3.000
GED_1.5                  -1589.54          0.511          1.181          3.762
SymHyperbolic            -1616.90          0.511          1.181          4.476
Ranking: Normal, GED_1.5, Logistic, t_6, Hyperbolic Sech, SymHyperbolic, Laplace, t_3

Dataset: Normal(mu=0.5, sigma=1.2) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.429          1.190          3.095
Normal                   -1592.54          0.429          1.190          3.000
Laplace                  -1640.87          0.402          1.342          6.000
Hyperbolic Sech          -1615.42          0.429          1.190          5.000
Logistic                 -1601.83          0.429          1.190          4.200
t_3                      -1690.02          0.429          1.190            inf
t_6                      -1607.88          0.429          1.190          3.000
GED_1.5                  -1600.66          0.429          1.190          3.762
SymHyperbolic            -1628.67          0.429          1.190          4.485
Ranking: Normal, GED_1.5, Logistic, t_6, Hyperbolic Sech, SymHyperbolic, Laplace, t_3

Dataset: Normal(mu=0.5, sigma=1.2) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.505          1.217          3.262
Normal                   -1615.10          0.505          1.217          3.000
Laplace                  -1647.28          0.480          1.351          6.000
Hyperbolic Sech          -1627.02          0.505          1.217          5.000
Logistic                 -1618.07          0.505          1.217          4.200
t_3                      -1692.21          0.505          1.217            inf
t_6                      -1623.16          0.505          1.217          3.000
GED_1.5                  -1615.96          0.505          1.217          3.762
SymHyperbolic            -1640.54          0.505          1.217          4.512
Ranking: Normal, GED_1.5, Logistic, t_6, Hyperbolic Sech, SymHyperbolic, Laplace, t_3

Dataset: Normal(mu=0.5, sigma=1.2) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.534          1.191          2.895
Normal                   -1594.14          0.534          1.191          3.000
Laplace                  -1652.18          0.524          1.357          6.000
Hyperbolic Sech          -1624.78          0.534          1.191          5.000
Logistic                 -1608.45          0.534          1.191          4.200
t_3                      -1705.62          0.534          1.191            inf
t_6                      -1615.44          0.534          1.191          3.000
GED_1.5                  -1607.08          0.534          1.191          3.762
SymHyperbolic            -1638.81          0.534          1.191          4.487
Ranking: Normal, GED_1.5, Logistic, t_6, Hyperbolic Sech, SymHyperbolic, Laplace, t_3

Dataset: Laplace(mu=-1.0, b=0.8) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -1.039          1.111          6.049
Normal                   -1524.28         -1.039          1.111          3.000
Laplace                  -1448.21         -1.029          1.107          6.000
Hyperbolic Sech          -1458.58         -1.039          1.111          5.000
Logistic                 -1473.04         -1.039          1.111          4.200
t_3                      -1464.05         -1.039          1.111            inf
t_6                      -1467.16         -1.039          1.111          3.000
GED_1.5                  -1475.33         -1.039          1.111          3.762
SymHyperbolic            -1464.66         -1.039          1.111          4.403
Ranking: Laplace, Hyperbolic Sech, t_3, SymHyperbolic, t_6, Logistic, GED_1.5, Normal

Dataset: Laplace(mu=-1.0, b=0.8) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -1.013          1.126          4.970
Normal                   -1537.74         -1.013          1.126          3.000
Laplace                  -1475.27         -1.028          1.137          6.000
Hyperbolic Sech          -1485.13         -1.013          1.126          5.000
Logistic                 -1497.78         -1.013          1.126          4.200
t_3                      -1498.77         -1.013          1.126            inf
t_6                      -1494.63         -1.013          1.126          3.000
GED_1.5                  -1496.63         -1.013          1.126          3.762
SymHyperbolic            -1492.32         -1.013          1.126          4.419
Ranking: Laplace, Hyperbolic Sech, SymHyperbolic, t_6, GED_1.5, Logistic, t_3, Normal

Dataset: Laplace(mu=-1.0, b=0.8) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.966          1.128          6.300
Normal                   -1539.70         -0.966          1.128          3.000
Laplace                  -1467.93         -1.000          1.129          6.000
Hyperbolic Sech          -1474.88         -0.966          1.128          5.000
Logistic                 -1487.86         -0.966          1.128          4.200
t_3                      -1481.86         -0.966          1.128            inf
t_6                      -1481.65         -0.966          1.128          3.000
GED_1.5                  -1491.84         -0.966          1.128          3.762
SymHyperbolic            -1480.41         -0.966          1.128          4.422
Ranking: Laplace, Hyperbolic Sech, SymHyperbolic, t_6, t_3, Logistic, GED_1.5, Normal

Dataset: Laplace(mu=-1.0, b=0.8) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -1.025          1.091          4.765
Normal                   -1505.58         -1.025          1.091          3.000
Laplace                  -1449.88         -1.021          1.109          6.000
Hyperbolic Sech          -1459.49         -1.025          1.091          5.000
Logistic                 -1470.65         -1.025          1.091          4.200
t_3                      -1477.98         -1.025          1.091            inf
t_6                      -1468.64         -1.025          1.091          3.000
GED_1.5                  -1468.07         -1.025          1.091          3.762
SymHyperbolic            -1467.39         -1.025          1.091          4.381
Ranking: Laplace, Hyperbolic Sech, SymHyperbolic, GED_1.5, t_6, Logistic, t_3, Normal

Dataset: Laplace(mu=-1.0, b=0.8) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.966          1.137          5.351
Normal                   -1546.97         -0.966          1.137          3.000
Laplace                  -1483.30         -0.949          1.147          6.000
Hyperbolic Sech          -1492.87         -0.966          1.137          5.000
Logistic                 -1505.04         -0.966          1.137          4.200
t_3                      -1506.33         -0.966          1.137            inf
t_6                      -1501.29         -0.966          1.137          3.000
GED_1.5                  -1504.90         -0.966          1.137          3.762
SymHyperbolic            -1499.60         -0.966          1.137          4.430
Ranking: Laplace, Hyperbolic Sech, SymHyperbolic, t_6, GED_1.5, Logistic, t_3, Normal

Dataset: Hyperbolic Sech(mu=0.0, sigma=1.0) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.000          1.000          3.860
Normal                   -1418.66          0.000          1.000          3.000
Laplace                  -1419.03          0.020          1.075          6.000
Hyperbolic Sech          -1407.11          0.000          1.000          5.000
Logistic                 -1405.44          0.000          1.000          4.200
t_3                      -1453.69          0.000          1.000            inf
t_6                      -1407.32          0.000          1.000          3.000
GED_1.5                  -1404.70          0.000          1.000          3.762
SymHyperbolic            -1413.11          0.000          1.000          4.276
Ranking: GED_1.5, Logistic, Hyperbolic Sech, t_6, SymHyperbolic, Normal, Laplace, t_3

Dataset: Hyperbolic Sech(mu=0.0, sigma=1.0) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.047          0.979          4.870
Normal                   -1397.55          0.047          0.979          3.000
Laplace                  -1386.41          0.049          1.041          6.000
Hyperbolic Sech          -1368.35          0.047          0.979          5.000
Logistic                 -1369.21          0.047          0.979          4.200
t_3                      -1403.19          0.047          0.979            inf
t_6                      -1367.39          0.047          0.979          3.000
GED_1.5                  -1374.43          0.047          0.979          3.762
SymHyperbolic            -1373.26          0.047          0.979          4.251
Ranking: t_6, Hyperbolic Sech, Logistic, SymHyperbolic, GED_1.5, Laplace, Normal, t_3

Dataset: Hyperbolic Sech(mu=0.0, sigma=1.0) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.021          0.999          7.044
Normal                   -1417.63         -0.021          0.999          3.000
Laplace                  -1392.52          0.017          1.047          6.000
Hyperbolic Sech          -1377.96         -0.021          0.999          5.000
Logistic                 -1379.31         -0.021          0.999          4.200
t_3                      -1408.51         -0.021          0.999            inf
t_6                      -1375.11         -0.021          0.999          3.000
GED_1.5                  -1386.85         -0.021          0.999          3.762
SymHyperbolic            -1381.95         -0.021          0.999          4.275
Ranking: t_6, Hyperbolic Sech, Logistic, SymHyperbolic, GED_1.5, Laplace, t_3, Normal

Dataset: Hyperbolic Sech(mu=0.0, sigma=1.0) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.017          1.011          4.010
Normal                   -1430.30          0.017          1.011          3.000
Laplace                  -1429.48          0.033          1.086          6.000
Hyperbolic Sech          -1415.82          0.017          1.011          5.000
Logistic                 -1414.47          0.017          1.011          4.200
t_3                      -1460.43          0.017          1.011            inf
t_6                      -1415.71          0.017          1.011          3.000
GED_1.5                  -1415.09          0.017          1.011          3.762
SymHyperbolic            -1421.85          0.017          1.011          4.290
Ranking: Logistic, GED_1.5, t_6, Hyperbolic Sech, SymHyperbolic, Laplace, Normal, t_3

Dataset: Hyperbolic Sech(mu=0.0, sigma=1.0) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.008          1.026          5.189
Normal                   -1444.44         -0.008          1.026          3.000
Laplace                  -1400.84          0.011          1.056          6.000
Hyperbolic Sech          -1399.19         -0.008          1.026          5.000
Logistic                 -1407.04         -0.008          1.026          4.200
t_3                      -1420.34         -0.008          1.026            inf
t_6                      -1403.88         -0.008          1.026          3.000
GED_1.5                  -1409.42         -0.008          1.026          3.762
SymHyperbolic            -1406.10         -0.008          1.026          4.307
Ranking: Hyperbolic Sech, Laplace, t_6, SymHyperbolic, Logistic, GED_1.5, t_3, Normal

Dataset: Logistic(mu=1.0, scale=0.7) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          1.008          1.248          4.165
Normal                   -1640.80          1.008          1.248          3.000
Laplace                  -1647.24          1.011          1.351          6.000
Hyperbolic Sech          -1628.66          1.008          1.248          5.000
Logistic                 -1625.99          1.008          1.248          4.200
t_3                      -1675.78          1.008          1.248            inf
t_6                      -1627.30          1.008          1.248          3.000
GED_1.5                  -1627.60          1.008          1.248          3.762
SymHyperbolic            -1640.33          1.008          1.248          4.542
Ranking: Logistic, t_6, GED_1.5, Hyperbolic Sech, SymHyperbolic, Normal, Laplace, t_3

Dataset: Logistic(mu=1.0, scale=0.7) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          1.019          1.264          4.088
Normal                   -1653.13          1.019          1.264          3.000
Laplace                  -1655.78          1.002          1.362          6.000
Hyperbolic Sech          -1641.85          1.019          1.264          5.000
Logistic                 -1639.14          1.019          1.264          4.200
t_3                      -1689.48          1.019          1.264            inf
t_6                      -1640.63          1.019          1.264          3.000
GED_1.5                  -1639.48          1.019          1.264          3.762
SymHyperbolic            -1654.00          1.019          1.264          4.557
Ranking: Logistic, GED_1.5, t_6, Hyperbolic Sech, Normal, SymHyperbolic, Laplace, t_3

Dataset: Logistic(mu=1.0, scale=0.7) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.984          1.279          3.495
Normal                   -1665.38          0.984          1.279          3.000
Laplace                  -1683.14          0.988          1.400          6.000
Hyperbolic Sech          -1667.50          0.984          1.279          5.000
Logistic                 -1661.57          0.984          1.279          4.200
t_3                      -1724.87          0.984          1.279            inf
t_6                      -1665.34          0.984          1.279          3.000
GED_1.5                  -1659.88          0.984          1.279          3.762
SymHyperbolic            -1682.13          0.984          1.279          4.572
Ranking: GED_1.5, Logistic, t_6, Normal, Hyperbolic Sech, SymHyperbolic, Laplace, t_3

Dataset: Logistic(mu=1.0, scale=0.7) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.999          1.264          4.111
Normal                   -1653.05          0.999          1.264          3.000
Laplace                  -1648.23          0.998          1.352          6.000
Hyperbolic Sech          -1634.74          0.999          1.264          5.000
Logistic                 -1634.86          0.999          1.264          4.200
t_3                      -1676.24          0.999          1.264            inf
t_6                      -1635.69          0.999          1.264          3.000
GED_1.5                  -1635.58          0.999          1.264          3.762
SymHyperbolic            -1646.00          0.999          1.264          4.557
Ranking: Hyperbolic Sech, Logistic, GED_1.5, t_6, SymHyperbolic, Laplace, Normal, t_3

Dataset: Logistic(mu=1.0, scale=0.7) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.940          1.312          4.184
Normal                   -1690.14          0.940          1.312          3.000
Laplace                  -1698.28          0.937          1.421          6.000
Hyperbolic Sech          -1680.50          0.940          1.312          5.000
Logistic                 -1676.36          0.940          1.312          4.200
t_3                      -1730.08          0.940          1.312            inf
t_6                      -1677.67          0.940          1.312          3.000
GED_1.5                  -1678.03          0.940          1.312          3.762
SymHyperbolic            -1694.34          0.940          1.312          4.601
Ranking: Logistic, t_6, GED_1.5, Hyperbolic Sech, Normal, SymHyperbolic, Laplace, t_3

Dataset: t_3(mu=0.0, scale=1.0) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.011          1.953         28.913
Normal                   -2088.26          0.011          1.953          3.000
Laplace                  -1873.78         -0.060          1.694          6.000
Hyperbolic Sech          -1897.31          0.011          1.953          5.000
Logistic                 -1925.82          0.011          1.953          4.200
t_3                      -1834.51          0.011          1.953            inf
t_6                      -1895.25          0.011          1.953          3.000
GED_1.5                  -1960.09          0.011          1.953          3.762
SymHyperbolic            -1866.41          0.011          1.953          5.037
Ranking: t_3, SymHyperbolic, Laplace, t_6, Hyperbolic Sech, Logistic, GED_1.5, Normal

Dataset: t_3(mu=0.0, scale=1.0) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.012          1.977         53.189
Normal                   -2100.67          0.012          1.977          3.000
Laplace                  -1858.66         -0.012          1.669          6.000
Hyperbolic Sech          -1895.07          0.012          1.977          5.000
Logistic                 -1925.98          0.012          1.977          4.200
t_3                      -1829.23          0.012          1.977            inf
t_6                      -1896.03          0.012          1.977          3.000
GED_1.5                  -1958.24          0.012          1.977          3.762
SymHyperbolic            -1856.28          0.012          1.977          5.050
Ranking: t_3, SymHyperbolic, Laplace, Hyperbolic Sech, t_6, Logistic, GED_1.5, Normal

Dataset: t_3(mu=0.0, scale=1.0) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.014          1.711         16.785
Normal                   -1955.84          0.014          1.711          3.000
Laplace                  -1806.14          0.034          1.583          6.000
Hyperbolic Sech          -1821.31          0.014          1.711          5.000
Logistic                 -1842.89          0.014          1.711          4.200
t_3                      -1788.84          0.014          1.711            inf
t_6                      -1822.72          0.014          1.711          3.000
GED_1.5                  -1863.60          0.014          1.711          3.762
SymHyperbolic            -1807.93          0.014          1.711          4.901
Ranking: t_3, Laplace, SymHyperbolic, Hyperbolic Sech, t_6, Logistic, GED_1.5, Normal

Dataset: t_3(mu=0.0, scale=1.0) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.016          1.530          6.120
Normal                   -1844.52         -0.016          1.530          3.000
Laplace                  -1785.00          0.001          1.550          6.000
Hyperbolic Sech          -1782.83         -0.016          1.530          5.000
Logistic                 -1793.61         -0.016          1.530          4.200
t_3                      -1792.83         -0.016          1.530            inf
t_6                      -1787.20         -0.016          1.530          3.000
GED_1.5                  -1799.98         -0.016          1.530          3.762
SymHyperbolic            -1788.70         -0.016          1.530          4.778
Ranking: Hyperbolic Sech, Laplace, t_6, SymHyperbolic, t_3, Logistic, GED_1.5, Normal

Dataset: t_3(mu=0.0, scale=1.0) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.041          1.748         19.528
Normal                   -1977.19         -0.041          1.748          3.000
Laplace                  -1807.07         -0.038          1.585          6.000
Hyperbolic Sech          -1824.82         -0.041          1.748          5.000
Logistic                 -1848.61         -0.041          1.748          4.200
t_3                      -1782.91         -0.041          1.748            inf
t_6                      -1824.94         -0.041          1.748          3.000
GED_1.5                  -1873.38         -0.041          1.748          3.762
SymHyperbolic            -1806.09         -0.041          1.748          4.923
Ranking: t_3, SymHyperbolic, Laplace, Hyperbolic Sech, t_6, Logistic, GED_1.5, Normal

Dataset: t_6(mu=0.0, scale=1.0) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.110          1.233          5.600
Normal                   -1628.05          0.110          1.233          3.000
Laplace                  -1608.96          0.076          1.300          6.000
Hyperbolic Sech          -1594.30          0.110          1.233          5.000
Logistic                 -1595.29          0.110          1.233          4.200
t_3                      -1627.21          0.110          1.233            inf
t_6                      -1592.26          0.110          1.233          3.000
GED_1.5                  -1601.17          0.110          1.233          3.762
SymHyperbolic            -1602.52          0.110          1.233          4.527
Ranking: t_6, Hyperbolic Sech, Logistic, GED_1.5, SymHyperbolic, Laplace, t_3, Normal

Dataset: t_6(mu=0.0, scale=1.0) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.026          1.212          4.838
Normal                   -1611.13         -0.026          1.212          3.000
Laplace                  -1606.65         -0.018          1.297          6.000
Hyperbolic Sech          -1588.76         -0.026          1.212          5.000
Logistic                 -1587.22         -0.026          1.212          4.200
t_3                      -1629.41         -0.026          1.212            inf
t_6                      -1586.20         -0.026          1.212          3.000
GED_1.5                  -1591.66         -0.026          1.212          3.762
SymHyperbolic            -1598.05         -0.026          1.212          4.507
Ranking: t_6, Logistic, Hyperbolic Sech, GED_1.5, SymHyperbolic, Laplace, Normal, t_3

Dataset: t_6(mu=0.0, scale=1.0) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.017          1.168          3.880
Normal                   -1573.90          0.017          1.168          3.000
Laplace                  -1579.24          0.044          1.262          6.000
Hyperbolic Sech          -1564.24          0.017          1.168          5.000
Logistic                 -1561.41          0.017          1.168          4.200
t_3                      -1612.66          0.017          1.168            inf
t_6                      -1563.31          0.017          1.168          3.000
GED_1.5                  -1561.56          0.017          1.168          3.762
SymHyperbolic            -1574.04          0.017          1.168          4.463
Ranking: Logistic, GED_1.5, t_6, Hyperbolic Sech, Normal, SymHyperbolic, Laplace, t_3

Dataset: t_6(mu=0.0, scale=1.0) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.040          1.166          4.459
Normal                   -1572.15          0.040          1.166          3.000
Laplace                  -1567.41          0.034          1.247          6.000
Hyperbolic Sech          -1554.24          0.040          1.166          5.000
Logistic                 -1552.76          0.040          1.166          4.200
t_3                      -1597.27          0.040          1.166            inf
t_6                      -1553.02          0.040          1.166          3.000
GED_1.5                  -1554.50          0.040          1.166          3.762
SymHyperbolic            -1563.07          0.040          1.166          4.461
Ranking: Logistic, t_6, Hyperbolic Sech, GED_1.5, SymHyperbolic, Laplace, Normal, t_3

Dataset: t_6(mu=0.0, scale=1.0) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.044          1.191          5.309
Normal                   -1593.85         -0.044          1.191          3.000
Laplace                  -1571.79         -0.030          1.253          6.000
Hyperbolic Sech          -1557.42         -0.044          1.191          5.000
Logistic                 -1559.52         -0.044          1.191          4.200
t_3                      -1587.42         -0.044          1.191            inf
t_6                      -1556.25         -0.044          1.191          3.000
GED_1.5                  -1565.78         -0.044          1.191          3.762
SymHyperbolic            -1564.78         -0.044          1.191          4.486
Ranking: t_6, Hyperbolic Sech, Logistic, SymHyperbolic, GED_1.5, Laplace, t_3, Normal

Dataset: GED_1.5(mu=0.0, beta=1.0) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.006          0.794          3.278
Normal                   -1188.26          0.006          0.794          3.000
Laplace                  -1208.55          0.003          0.871          6.000
Hyperbolic Sech          -1194.97          0.006          0.794          5.000
Logistic                 -1188.49          0.006          0.794          4.200
t_3                      -1255.47          0.006          0.794            inf
t_6                      -1193.23          0.006          0.794          3.000
GED_1.5                  -1184.82          0.006          0.794          3.762
SymHyperbolic            -1194.23          0.006          0.794          4.006
Ranking: GED_1.5, Normal, Logistic, t_6, SymHyperbolic, Hyperbolic Sech, Laplace, t_3

Dataset: GED_1.5(mu=0.0, beta=1.0) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.010          0.859          3.979
Normal                   -1267.43          0.010          0.859          3.000
Laplace                  -1271.99          0.014          0.928          6.000
Hyperbolic Sech          -1257.70          0.010          0.859          5.000
Logistic                 -1255.09          0.010          0.859          4.200
t_3                      -1306.19          0.010          0.859            inf
t_6                      -1257.05          0.010          0.859          3.000
GED_1.5                  -1254.76          0.010          0.859          3.762
SymHyperbolic            -1260.53          0.010          0.859          4.097
Ranking: GED_1.5, Logistic, t_6, Hyperbolic Sech, SymHyperbolic, Normal, Laplace, t_3

Dataset: GED_1.5(mu=0.0, beta=1.0) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.017          0.885          3.976
Normal                   -1296.30         -0.017          0.885          3.000
Laplace                  -1290.01         -0.004          0.945          6.000
Hyperbolic Sech          -1280.91         -0.017          0.885          5.000
Logistic                 -1280.80         -0.017          0.885          4.200
t_3                      -1324.36         -0.017          0.885            inf
t_6                      -1282.30         -0.017          0.885          3.000
GED_1.5                  -1279.61         -0.017          0.885          3.762
SymHyperbolic            -1285.59         -0.017          0.885          4.131
Ranking: GED_1.5, Logistic, Hyperbolic Sech, t_6, SymHyperbolic, Laplace, Normal, t_3

Dataset: GED_1.5(mu=0.0, beta=1.0) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.026          0.826          3.001
Normal                   -1228.34          0.026          0.826          3.000
Laplace                  -1266.39          0.021          0.923          6.000
Hyperbolic Sech          -1246.61          0.026          0.826          5.000
Logistic                 -1236.17          0.026          0.826          4.200
t_3                      -1316.43          0.026          0.826            inf
t_6                      -1242.36          0.026          0.826          3.000
GED_1.5                  -1232.83          0.026          0.826          3.762
SymHyperbolic            -1244.25          0.026          0.826          4.052
Ranking: Normal, GED_1.5, Logistic, t_6, SymHyperbolic, Hyperbolic Sech, Laplace, t_3

Dataset: GED_1.5(mu=0.0, beta=1.0) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.020          0.896          3.844
Normal                   -1309.29          0.020          0.896          3.000
Laplace                  -1310.69         -0.014          0.965          6.000
Hyperbolic Sech          -1296.94          0.020          0.896          5.000
Logistic                 -1295.82          0.020          0.896          4.200
t_3                      -1342.65          0.020          0.896            inf
t_6                      -1297.76          0.020          0.896          3.000
GED_1.5                  -1295.46          0.020          0.896          3.762
SymHyperbolic            -1301.31          0.020          0.896          4.146
Ranking: GED_1.5, Logistic, Hyperbolic Sech, t_6, SymHyperbolic, Normal, Laplace, t_3

Dataset: SymHyperbolic(mu=0.0, alpha=1.3) [group 1] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.005          1.197          5.797
Normal                   -1598.65          0.005          1.197          3.000
Laplace                  -1559.68          0.023          1.238          6.000
Hyperbolic Sech          -1551.52          0.005          1.197          5.000
Logistic                 -1557.58          0.005          1.197          4.200
t_3                      -1573.19          0.005          1.197            inf
t_6                      -1553.12          0.005          1.197          3.000
GED_1.5                  -1563.27          0.005          1.197          3.762
SymHyperbolic            -1557.95          0.005          1.197          4.492
Ranking: Hyperbolic Sech, t_6, Logistic, SymHyperbolic, Laplace, GED_1.5, t_3, Normal

Dataset: SymHyperbolic(mu=0.0, alpha=1.3) [group 2] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.070          1.153          5.108
Normal                   -1561.26         -0.070          1.153          3.000
Laplace                  -1539.52          0.016          1.213          6.000
Hyperbolic Sech          -1528.33         -0.070          1.153          5.000
Logistic                 -1531.39         -0.070          1.153          4.200
t_3                      -1560.04         -0.070          1.153            inf
t_6                      -1529.53         -0.070          1.153          3.000
GED_1.5                  -1535.15         -0.070          1.153          3.762
SymHyperbolic            -1535.81         -0.070          1.153          4.447
Ranking: Hyperbolic Sech, t_6, Logistic, GED_1.5, SymHyperbolic, Laplace, t_3, Normal

Dataset: SymHyperbolic(mu=0.0, alpha=1.3) [group 3] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.005          1.139          5.327
Normal                   -1549.12         -0.005          1.139          3.000
Laplace                  -1540.67          0.027          1.214          6.000
Hyperbolic Sech          -1525.26         -0.005          1.139          5.000
Logistic                 -1524.81         -0.005          1.139          4.200
t_3                      -1564.89         -0.005          1.139            inf
t_6                      -1524.01         -0.005          1.139          3.000
GED_1.5                  -1528.10         -0.005          1.139          3.762
SymHyperbolic            -1532.87         -0.005          1.139          4.433
Ranking: t_6, Logistic, Hyperbolic Sech, GED_1.5, SymHyperbolic, Laplace, Normal, t_3

Dataset: SymHyperbolic(mu=0.0, alpha=1.3) [group 4] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan         -0.036          1.218          6.177
Normal                   -1616.37         -0.036          1.218          3.000
Laplace                  -1580.37         -0.052          1.263          6.000
Hyperbolic Sech          -1571.68         -0.036          1.218          5.000
Logistic                 -1576.20         -0.036          1.218          4.200
t_3                      -1596.33         -0.036          1.218            inf
t_6                      -1571.77         -0.036          1.218          3.000
GED_1.5                  -1581.91         -0.036          1.218          3.762
SymHyperbolic            -1578.36         -0.036          1.218          4.513
Ranking: Hyperbolic Sech, t_6, Logistic, SymHyperbolic, Laplace, GED_1.5, t_3, Normal

Dataset: SymHyperbolic(mu=0.0, alpha=1.3) [group 5] (1000 samples)
Model                      LogLik           Mean         StdDev       Kurtosis
------------------------------------------------------------------------------
Empirical                     nan          0.018          1.197          6.464
Normal                   -1598.93          0.018          1.197          3.000
Laplace                  -1564.18          0.016          1.243          6.000
Hyperbolic Sech          -1555.20          0.018          1.197          5.000
Logistic                 -1560.12          0.018          1.197          4.200
t_3                      -1580.27          0.018          1.197            inf
t_6                      -1556.34          0.018          1.197          3.000
GED_1.5                  -1565.19          0.018          1.197          3.762
SymHyperbolic            -1561.92          0.018          1.197          4.493
Ranking: Hyperbolic Sech, t_6, Logistic, SymHyperbolic, Laplace, GED_1.5, t_3, Normal
```
