'''
8. 字符串转换整数 (atoi)
'''
MAX = 2 ** 31 - 1
MIN = -2 ** 31
NUM = "0123456789"


class Solution:
    def myAtoi(self, s: str) -> int:
        if s == "":
            return 0
        '''
            num: 结果
            sgn: 正负
            n: 字符串长度
            i: 当前处理索引
        '''
        num, sgn, n, i = 0, 1, len(s), 0
        # 1. 去前缀空格
        while i < n and s[i] == ' ':
            i += 1
        if i == n:
            return 0
        # 2. 捕捉正负号
        if s[i] == '-':
            sgn = -1
            i += 1
        elif s[i] == '+':
            i += 1
        # 3. 处理
        while i < n:
            if s[i] not in NUM:
                break
            if num > MAX // 10 or \
                    (num == MAX // 10 and int(s[i]) > MAX % 10):
                return MAX if sgn == 1 else MIN
            num = num * 10 + int(s[i])
            i += 1

        return sgn * num

