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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: export/template-prototype.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b2507468f95156358fa490fd543ad2f0">export</a>
* <a href="{{ site.github.repository_url }}/blob/master/export/template-prototype.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 10:56:20+09:00




## Depends on

* :warning: <a href="../Util/IO/container-io.hpp.html">コンテナの入出力 <small>(Util/IO/container-io.hpp)</small></a>
* :heavy_check_mark: <a href="../Util/IO/io-setup.hpp.html">ioSetup() (iostreamの高速化と実数出力の設定) <small>(Util/IO/io-setup.hpp)</small></a>
* :warning: <a href="../Util/IO/join-into-ostream.hpp.html">join() (要素を区切り文字で結合して出力) <small>(Util/IO/join-into-ostream.hpp)</small></a>
* :heavy_check_mark: <a href="../Util/IO/println.hpp.html">println() (可変個の値を空白区切りで出力して改行する) <small>(Util/IO/println.hpp)</small></a>
* :warning: <a href="../Util/IO/var-declaration-with-input.hpp.html">複数変数宣言をして同時に入力もするやつ <small>(Util/IO/var-declaration-with-input.hpp)</small></a>
* :warning: <a href="../Util/all-macro.hpp.html">all()マクロ <small>(Util/all-macro.hpp)</small></a>
* :warning: <a href="../Util/bye.hpp.html">bye() (出力してexit(0)) <small>(Util/bye.hpp)</small></a>
* :warning: <a href="../Util/chminmax.hpp.html">chmin(), chmax() <small>(Util/chminmax.hpp)</small></a>
* :warning: <a href="../Util/div-ceil.hpp.html">divceil() (切り上げ除算) <small>(Util/div-ceil.hpp)</small></a>
* :heavy_check_mark: <a href="../Util/int-alias.hpp.html">int-alias (整数型のエイリアス) <small>(Util/int-alias.hpp)</small></a>
* :warning: <a href="../Util/int-infinity.hpp.html">int-infinity (整数のデカイ値) <small>(Util/int-infinity.hpp)</small></a>
* :warning: <a href="../Util/rep-macro.hpp.html">rep()マクロ <small>(Util/rep-macro.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

#if 1  // {{{

#include "../Util/all-macro.hpp"
#include "../Util/rep-macro.hpp"

#define let const auto
#include "../Util/int-alias.hpp"

#include "../Util/int-infinity.hpp"

#include "../Util/IO/io-setup.hpp"

#include "../Util/IO/var-declaration-with-input.hpp"

#include "../Util/IO/println.hpp"

#include "../Util/IO/container-io.hpp"

#include "../Util/IO/join-into-ostream.hpp"

#include "../Util/bye.hpp"

#include "../Util/chminmax.hpp"

#include "../Util/div-ceil.hpp"

#endif  // }}}

// constexpr int MOD = int(1e9) + 7;
// constexpr int MOD = 998244353;

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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: export/template-prototype.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

