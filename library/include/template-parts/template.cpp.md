---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: include/template-parts/template.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d5567e78d3674558c180d2f4feaa863b">include/template-parts</a>
* <a href="{{ site.github.repository_url }}/blob/master/include/template-parts/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 20:45:32+09:00




## Depends on

* :warning: <a href="all-macro.hpp.html">all()マクロ <small>(include/template-parts/all-macro.hpp)</small></a>
* :warning: <a href="bye.hpp.html">bye() (出力してexit(0)) <small>(include/template-parts/bye.hpp)</small></a>
* :warning: <a href="chminmax.hpp.html">chmin(), chmax() <small>(include/template-parts/chminmax.hpp)</small></a>
* :warning: <a href="constant.hpp.html">よく使う定数 <small>(include/template-parts/constant.hpp)</small></a>
* :warning: <a href="container-io.hpp.html">コンテナの入出力 <small>(include/template-parts/container-io.hpp)</small></a>
* :warning: <a href="div-ceil.hpp.html">divceil() (切り上げ除算) <small>(include/template-parts/div-ceil.hpp)</small></a>
* :heavy_check_mark: <a href="io-setup.hpp.html">ioSetup() (iostreamの高速化と実数出力の設定) <small>(include/template-parts/io-setup.hpp)</small></a>
* :warning: <a href="join-into-ostream.hpp.html">join() (要素を区切り文字で結合して出力) <small>(include/template-parts/join-into-ostream.hpp)</small></a>
* :warning: <a href="makeVec.hpp.html">makeVec() (多次元std::vectorの生成) <small>(include/template-parts/makeVec.hpp)</small></a>
* :heavy_check_mark: <a href="println.hpp.html">println() (可変個の値を空白区切りで出力して改行する) <small>(include/template-parts/println.hpp)</small></a>
* :warning: <a href="rep-macro.hpp.html">rep()マクロ <small>(include/template-parts/rep-macro.hpp)</small></a>
* :heavy_check_mark: <a href="type-alias.hpp.html">型エイリアス <small>(include/template-parts/type-alias.hpp)</small></a>
* :warning: <a href="var-declaration-with-input.hpp.html">複数変数宣言をして同時に入力もするやつ <small>(include/template-parts/var-declaration-with-input.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

#if 1  // {{{

#include "./all-macro.hpp"
#include "./rep-macro.hpp"

#include "./type-alias.hpp"

#include "./constant.hpp"

#include "./io-setup.hpp"

#include "./var-declaration-with-input.hpp"

#include "./println.hpp"

#include "./container-io.hpp"

#include "./join-into-ostream.hpp"

#include "./makeVec.hpp"

#include "./bye.hpp"

#include "./chminmax.hpp"

#include "./div-ceil.hpp"

#endif  // }}}

signed main() {
    ioSetup();

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: include/template-parts/template.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

