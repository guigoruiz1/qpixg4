
// Use this example configuration file as a starting point for your own files.
{
  seed: 123456, // Random number seed (omit to use time since Unix epoch)

  // Reaction matrix element files
  reactions: [ "ES.react" ],

  // Neutrino source specification
  source: {
    type: "histogram",
    neutrino: "ve",

    // Low edges of energy bins (MeV)
    E_bin_lefts: [ 0.011,  0.012,  0.013,  0.014,  0.015,  0.016,  0.017,  0.018,
      0.019,  0.02 ,  0.021,  0.022,  0.023,  0.024,  0.025,  0.026,
      0.027,  0.028,  0.029,  0.03 ,  0.031,  0.032,  0.033,  0.034,
      0.035,  0.036,  0.037,  0.038,  0.039,  0.04 ,  0.041,  0.042,
      0.043,  0.044,  0.045,  0.046,  0.047,  0.048,  0.049,  0.05 ,
      0.051,  0.052,  0.053,  0.054,  0.055,  0.056,  0.057,  0.058,
      0.059,  0.06 ,  0.061,  0.062,  0.063,  0.064,  0.065,  0.066,
      0.067,  0.068,  0.069,  0.07 ,  0.071,  0.072,  0.073,  0.074,
      0.075,  0.076,  0.077,  0.078,  0.079,  0.08 ,  0.081,  0.082,
      0.083,  0.084,  0.085,  0.086,  0.087,  0.088,  0.089,  0.09 ,
      0.091,  0.092,  0.093,  0.094,  0.095,  0.096,  0.097,  0.098,
      0.099,  0.1  ,  0.101,  0.102,  0.103,  0.104,  0.105,  0.106,
      0.107,  0.108,  0.109,  0.11 ,  0.111,  0.112,  0.113,  0.114,
      0.115,  0.116,  0.117,  0.118,  0.119,  0.12 ,  0.121,  0.122,
      0.123,  0.124,  0.125,  0.126,  0.127,  0.128,  0.129,  0.13 ,
      0.131,  0.132,  0.133,  0.134,  0.135,  0.136,  0.137,  0.138,
      0.139,  0.14 ,  0.141,  0.142,  0.143,  0.144,  0.145,  0.146,
      0.147,  0.148,  0.149,  0.15 ,  0.151,  0.152,  0.153,  0.154,
      0.155,  0.156,  0.157,  0.158,  0.159,  0.16 ,  0.161,  0.162,
      0.163,  0.164,  0.165,  0.166,  0.167,  0.168,  0.169,  0.17 ,
      0.171,  0.172,  0.173,  0.174,  0.175,  0.176,  0.177,  0.178,
      0.179,  0.18 ,  0.181,  0.182,  0.183,  0.184,  0.185,  0.186,
      0.187,  0.188,  0.189,  0.19 ,  0.191,  0.192,  0.193,  0.194,
      0.195,  0.196,  0.197,  0.198,  0.199,  0.2  ,  0.201,  0.202,
      0.203,  0.204,  0.205,  0.206,  0.207,  0.208,  0.209,  0.21 ,
      0.211,  0.212,  0.213,  0.214,  0.215,  0.216,  0.217,  0.218,
      0.219,  0.22 ,  0.221,  0.222,  0.223,  0.224,  0.225,  0.226,
      0.227,  0.228,  0.229,  0.23 ,  0.231,  0.232,  0.233,  0.234,
      0.235,  0.236,  0.237,  0.238,  0.239,  0.24 ,  0.241,  0.242,
      0.243,  0.244,  0.245,  0.246,  0.247,  0.248,  0.249,  0.25 ,
      0.251,  0.252,  0.253,  0.254,  0.255,  0.256,  0.257,  0.258,
      0.259,  0.26 ,  0.261,  0.262,  0.263,  0.264,  0.265,  0.266,
      0.267,  0.268,  0.269,  0.27 ,  0.271,  0.272,  0.273,  0.274,
      0.275,  0.276,  0.277,  0.278,  0.279,  0.28 ,  0.281,  0.282,
      0.283,  0.284,  0.285,  0.286,  0.287,  0.288,  0.289,  0.29 ,
      0.291,  0.292,  0.293,  0.294,  0.295,  0.296,  0.297,  0.298,
      0.299,  0.3  ,  0.301,  0.302,  0.303,  0.304,  0.305,  0.306,
      0.307,  0.308,  0.309,  0.31 ,  0.311,  0.312,  0.313,  0.314,
      0.315,  0.316,  0.317,  0.318,  0.319,  0.32 ,  0.321,  0.322,
      0.323,  0.324,  0.325,  0.326,  0.327,  0.328,  0.329,  0.33 ,
      0.331,  0.332,  0.333,  0.334,  0.335,  0.336,  0.337,  0.338,
      0.339,  0.34 ,  0.341,  0.342,  0.343,  0.344,  0.345,  0.346,
      0.347,  0.348,  0.349,  0.35 ,  0.351,  0.352,  0.353,  0.354,
      0.355,  0.356,  0.357,  0.358,  0.359,  0.36 ,  0.361,  0.362,
      0.363,  0.364,  0.365,  0.366,  0.367,  0.368,  0.369,  0.37 ,
      0.371,  0.372,  0.373,  0.374,  0.375,  0.376,  0.377,  0.378,
      0.379,  0.38 ,  0.381,  0.382,  0.383,  0.384,  0.385,  0.386,
      0.387,  0.388,  0.389,  0.39 ,  0.391,  0.392,  0.393,  0.394,
      0.395,  0.396,  0.397,  0.398,  0.399,  0.4  ,  0.401,  0.402,
      0.403,  0.404,  0.405,  0.406,  0.407,  0.408,  0.409,  0.41 ,
      0.411,  0.412,  0.413,  0.414,  0.415,  0.416,  0.417,  0.418,
      0.419,  0.42 ,  0.421,  0.422,  0.423],

    // Bin weights (dimensionless)
    weights: [    965.41062,    1145.8823 ,    1341.2605 ,    1551.4205 ,
        1776.2377 ,    2015.5877 ,    2269.3466 ,    2537.3905 ,
        2819.5959 ,    3115.8394 ,    3425.9981 ,    3749.9492 ,
        4087.57   ,    4438.7383 ,    4803.332  ,    5181.2293 ,
        5572.3087 ,    5976.4488 ,    6393.5287 ,    6823.4274 ,
        7266.0245 ,    7721.1996 ,    8188.8326 ,    8668.8038 ,
        9160.9935 ,    9665.2824 ,   10181.552  ,   10709.682  ,
       11249.555  ,   11801.053  ,   12364.057  ,   12938.449  ,
       13524.112  ,   14120.929  ,   14728.782  ,   15347.554  ,
       15977.129  ,   16617.391  ,   17268.223  ,   17929.51   ,
       18601.136  ,   19282.984  ,   19974.941  ,   20676.892  ,
       21388.721  ,   22110.314  ,   22841.557  ,   23582.336  ,
       24332.537  ,   25092.047  ,   25860.753  ,   26638.541  ,
       27425.299  ,   28220.914  ,   29025.274  ,   29838.268  ,
       30659.782  ,   31489.706  ,   32327.928  ,   33174.337  ,
       34028.822  ,   34891.273  ,   35761.58   ,   36639.631  ,
       37525.318  ,   38418.53   ,   39319.158  ,   40227.093  ,
       41142.226  ,   42064.447  ,   42993.65   ,   43929.725  ,
       44872.563  ,   45822.059  ,   46778.103  ,   47740.589  ,
       48709.409  ,   49684.456  ,   50665.624  ,   51652.806  ,
       52645.897  ,   53644.79   ,   54649.378  ,   55659.558  ,
       56675.223  ,   57696.269  ,   58722.59   ,   59754.082  ,
       60790.641  ,   61832.162  ,   62878.541  ,   63929.675  ,
       64985.46   ,   66045.793  ,   67110.57   ,   68179.689  ,
       69253.048  ,   70330.543  ,   71412.073  ,   72497.535  ,
       73586.828  ,   74679.851  ,   75776.501  ,   76876.678  ,
       77980.282  ,   79087.21   ,   80197.363  ,   81310.64   ,
       82426.942  ,   83546.169  ,   84668.22   ,   85792.997  ,
       86920.4    ,   88050.33   ,   89182.689  ,   90317.378  ,
       91454.298  ,   92593.351  ,   93734.439  ,   94877.465  ,
       96022.331  ,   97168.939  ,   98317.193  ,   99466.995  ,
      100618.25   ,  101770.86   ,  102924.72   ,  104079.75   ,
      105235.85   ,  106392.92   ,  107550.86   ,  108709.58   ,
      109868.98   ,  111028.98   ,  112189.46   ,  113350.35   ,
      114511.55   ,  115672.95   ,  116834.47   ,  117996.02   ,
      119157.49   ,  120318.8    ,  121479.85   ,  122640.55   ,
      123800.8    ,  124960.52   ,  126119.61   ,  127277.98   ,
      128435.53   ,  129592.17   ,  130747.82   ,  131902.37   ,
      133055.75   ,  134207.84   ,  135358.58   ,  136507.86   ,
      137655.59   ,  138801.68   ,  139946.04   ,  141088.58   ,
      142229.21   ,  143367.85   ,  144504.39   ,  145638.75   ,
      146770.84   ,  147900.57   ,  149027.85   ,  150152.59   ,
      151274.71   ,  152394.11   ,  153510.7    ,  154624.39   ,
      155735.1    ,  156842.74   ,  157947.22   ,  159048.44   ,
      160146.33   ,  161240.8    ,  162331.75   ,  163419.1    ,
      164502.75   ,  165582.64   ,  166658.65   ,  167730.72   ,
      168798.74   ,  169862.64   ,  170922.32   ,  171977.7    ,
      173028.69   ,  174075.21   ,  175117.17   ,  176154.48   ,
      177187.05   ,  178214.8    ,  179237.64   ,  180255.48   ,
      181268.24   ,  182275.84   ,  183278.18   ,  184275.18   ,
      185266.76   ,  186252.82   ,  187233.28   ,  188208.06   ,
      189177.06   ,  190140.21   ,  191097.42   ,  192048.59   ,
      192993.65   ,  193932.51   ,  194865.09   ,  195791.29   ,
      196711.03   ,  197624.23   ,  198530.8    ,  199430.65   ,
      200323.69   ,  201209.85   ,  202089.04   ,  202961.16   ,
      203826.13   ,  204683.88   ,  205534.3    ,  206377.32   ,
      207212.84   ,  208040.79   ,  208861.07   ,  209673.6    ,
      210478.29   ,  211275.06   ,  212063.81   ,  212844.47   ,
      213616.93   ,  214381.13   ,  215136.96   ,  215884.34   ,
      216623.19   ,  217353.41   ,  218074.92   ,  218787.63   ,
      219491.44   ,  220186.28   ,  220872.05   ,  221548.67   ,
      222216.04   ,  222874.07   ,  223522.68   ,  224161.77   ,
      224791.25   ,  225411.04   ,  226021.04   ,  226621.16   ,
      227211.31   ,  227791.4    ,  228361.33   ,  228921.01   ,
      229470.35   ,  230009.26   ,  230537.63   ,  231055.39   ,
      231562.42   ,  232058.64   ,  232543.95   ,  233018.25   ,
      233481.46   ,  233933.46   ,  234374.16   ,  234803.47   ,
      235221.28   ,  235627.49   ,  236022.01   ,  236404.73   ,
      236775.56   ,  237134.38   ,  237481.09   ,  237815.6    ,
      238137.8    ,  238447.57   ,  238744.83   ,  239029.44   ,
      239301.32   ,  239560.35   ,  239806.42   ,  240039.42   ,
      240259.23   ,  240465.75   ,  240658.86   ,  240838.44   ,
      241004.38   ,  241156.56   ,  241294.85   ,  241419.15   ,
      241529.33   ,  241625.26   ,  241706.82   ,  241773.88   ,
      241826.32   ,  241864.     ,  241886.81   ,  241894.59   ,
      241887.22   ,  241864.56   ,  241826.48   ,  241772.82   ,
      241703.46   ,  241618.24   ,  241517.03   ,  241399.66   ,
      241265.98   ,  241115.85   ,  240949.11   ,  240765.6    ,
      240565.15   ,  240347.6    ,  240112.79   ,  239860.53   ,
      239590.66   ,  239303.     ,  238997.37   ,  238673.59   ,
      238331.45   ,  237970.78   ,  237591.38   ,  237193.03   ,
      236775.55   ,  236338.72   ,  235882.32   ,  235406.14   ,
      234909.94   ,  234393.51   ,  233856.6    ,  233298.96   ,
      232720.37   ,  232120.54   ,  231499.24   ,  230856.18   ,
      230191.09   ,  229503.69   ,  228793.68   ,  228060.76   ,
      227304.63   ,  226524.96   ,  225721.43   ,  224893.69   ,
      224041.4    ,  223164.19   ,  222261.69   ,  221333.51   ,
      220379.26   ,  219398.5    ,  218390.83   ,  217355.79   ,
      216292.91   ,  215201.72   ,  214081.73   ,  212932.4    ,
      211753.21   ,  210543.58   ,  209302.94   ,  208030.66   ,
      206726.12   ,  205388.64   ,  204017.52   ,  202612.03   ,
      201171.41   ,  199694.85   ,  198181.49   ,  196630.46   ,
      195040.81   ,  193411.55   ,  191741.64   ,  190029.98   ,
      188275.4    ,  186476.65   ,  184632.42   ,  182741.31   ,
      180801.84   ,  178812.4    ,  176771.31   ,  174676.72   ,
      172526.69   ,  170319.11   ,  168051.72   ,  165722.04   ,
      163327.42   ,  160864.97   ,  158331.53   ,  155723.65   ,
      153037.54   ,  150269.03   ,  147413.49   ,  144465.79   ,
      141420.21   ,  138270.32   ,  135008.85   ,  131627.55   ,
      128117.01   ,  124466.33   ,  120662.86   ,  116691.74   ,
      112535.3    ,  108172.27   ,  103576.64   ,   98716.029  ,
       93549.272  ,   88022.603  ,   82063.488  ,   75569.86   ,
       68389.826  ,   60278.832  ,   50793.112  ,   38941.06   ,
       21046.763  ],

    // Upper edge of the final bin (MeV)
    Emax: 0.424,
  },

  // Incident neutrino direction 3-vector
  direction: { x: 0.0, y: -1.0, z: 0.0 },

}