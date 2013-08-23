---
layout: news
title: 新闻
permalink: /
author: all
---

{% for post in site.posts %}
  {% include news_item.html %}
{% endfor %}
