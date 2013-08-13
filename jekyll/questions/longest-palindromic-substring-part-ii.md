---                                                                             
layout: questions                                                                    
title: 最长的回文子字符串 第二部 
prev_section: home                                                              
permalink: /longest-palindromic-substring-part-ii/
---

Given a string S, find the longest palindromic substring in S.

Note:
This is Part II of the article: Longest Palindromic Substring. Here, we describe an algorithm (Manacher’s algorithm) which finds the longest palindromic substring in linear time. Please read Part I for more background information.

In my previous post we discussed a total of four different methods, among them there’s a pretty simple algorithm with O(N2) run time and constant space complexity. Here, we discuss an algorithm that runs in O(N) time and O(N) space, also known as Manacher’s algorithm.

Hint:
Think how you would improve over the simpler O(N2) approach. Consider the worst case scenarios. The worst case scenarios are the inputs with multiple palindromes overlapping each other. For example, the inputs: “aaaaaaaaa” and “cabcbabcbabcba”. In fact, we could take advantage of the palindrome’s symmetric property and avoid some of the unnecessary computations.

An O(N) Solution (Manacher’s Algorithm):
First, we transform the input string, S, to another string T by inserting a special character ‘#’ in between letters. The reason for doing so will be immediately clear to you soon.

For example: S = “abaaba”, T = “#a#b#a#a#b#a#”.

To find the longest palindromic substring, we need to expand around each Ti such that Ti-d … Ti+d forms a palindrome. You should immediately see that d is the length of the palindrome itself centered at Ti.
