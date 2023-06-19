# Link da questão: https://leetcode.com/problems/multiply-strings/description/
# Referência: https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/karatsuba.html
"""
Questão de multiplicação normal e fácil, porém foi feita usando karatsuba
para colocar em prática o algoritmo aprendido em aula
"""


class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def karatsuba(x, y):
            if len(x) == 1 or len(y) == 1:
                return int(x) * int(y)

            n = min(len(x), len(y)) // 2
            p, q = x[:len(x) - n], x[len(x) - n:]
            r, s = y[:len(y) - n], y[len(y) - n:]

            pr = karatsuba(p, r)
            qs = karatsuba(q, s)
            pr_qs = karatsuba(str(int(p) + int(q)),
                              str(int(r) + int(s))) - pr - qs

            return 10**(2*n) * pr + 10**n * pr_qs + qs

        return str(karatsuba(num1, num2))
