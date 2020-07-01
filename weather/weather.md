## weather report





心知天气

参考资料：
https://blog.csdn.net/zhengnianli/article/details/95070044

private:
SBx4_FIjI6Y5CDu4V

public:
PFLRvkJQo66nci7AD





https://api.seniverse.com/v3/weather/now.json?key=your_private_key&location=shenzhen&language=zh-Hans&unit=c

```
{"results":[{"location":{"id":"WS10730EM8EV","name":"深圳","country":"CN","path":"深圳,深圳,广东,中国","timezone":"Asia/Shanghai","timezone_offset":"+08:00"},"now":{"text":"阴","code":"9","temperature":"30"},"last_update":"2020-07-01T18:09:00+08:00"}]}
```



```
{
    "results":  [{  
            "location": {
                "id":   "WS10730EM8EV",
                "name": "深圳",
                "country":  "CN",
                "path": "深圳,深圳,广东,中国",
                "timezone": "Asia/Shanghai",
                "timezone_offset":  "+08:00"
            },
            "now":  {
                "text": "阴",
                "code": "9",
                "temperature":  "30"
            },
            "last_update":  "2020-07-01T18:09:00+08:00"
        }]
}
```







https://api.seniverse.com/v3/weather/daily.json?key=your_private_key&location=shenzhen&language=zh-Hans&unit=c





```
{"results":[{"location":{"id":"WS10730EM8EV","name":"深圳","country":"CN","path":"深圳,深圳,广东,中国","timezone":"Asia/Shanghai","timezone_offset":"+08:00"},"daily":[{"date":"2020-07-01","text_day":"雷阵雨","code_day":"11","text_night":"雷阵雨","code_night":"11","high":"33","low":"26","rainfall":"6.3","precip":"","wind_direction":"无持续风向","wind_direction_degree":"165","wind_speed":"16.20","wind_scale":"3","humidity":"86"},{"date":"2020-07-02","text_day":"雷阵雨","code_day":"11","text_night":"雷阵雨","code_night":"11","high":"31","low":"26","rainfall":"11.2","precip":"","wind_direction":"南","wind_direction_degree":"188","wind_speed":"25.20","wind_scale":"4","humidity":"87"},{"date":"2020-07-03","text_day":"雷阵雨","code_day":"11","text_night":"雷阵雨","code_night":"11","high":"31","low":"27","rainfall":"6.3","precip":"","wind_direction":"南","wind_direction_degree":"170","wind_speed":"25.20","wind_scale":"4","humidity":"81"}],"last_update":"2020-07-01T17:19:58+08:00"}]}
```





```
{
    "results":  [{
            "location": {
                "id":   "WS10730EM8EV",
                "name": "深圳",
                "country":  "CN",
                "path": "深圳,深圳,广东,中国",
                "timezone": "Asia/Shanghai",
                "timezone_offset":  "+08:00"
            },
            "daily":    [{
                    "date": "2020-07-01",
                    "text_day": "雷阵雨",
                    "code_day": "11",
                    "text_night":   "雷阵雨",
                    "code_night":   "11",
                    "high": "33",
                    "low":  "26",
                    "rainfall": "6.3",
                    "precip":   "",
                    "wind_direction":   "无持续风向",
                    "wind_direction_degree":    "165",
                    "wind_speed":   "16.20",
                    "wind_scale":   "3",
                    "humidity": "86"
                }, {
                    "date": "2020-07-02",
                    "text_day": "雷阵雨",
                    "code_day": "11",
                    "text_night":   "雷阵雨",
                    "code_night":   "11",
                    "high": "31",
                    "low":  "26",
                    "rainfall": "11.2",
                    "precip":   "",
                    "wind_direction":   "南",
                    "wind_direction_degree":    "188",
                    "wind_speed":   "25.20",
                    "wind_scale":   "4",
                    "humidity": "87"
                }, {
                    "date": "2020-07-03",
                    "text_day": "雷阵雨",
                    "code_day": "11",
                    "text_night":   "雷阵雨",
                    "code_night":   "11",
                    "high": "31",
                    "low":  "27",
                    "rainfall": "6.3",
                    "precip":   "",
                    "wind_direction":   "南",
                    "wind_direction_degree":    "170",
                    "wind_speed":   "25.20",
                    "wind_scale":   "4",
                    "humidity": "81"
                }],
            "last_update":  "2020-07-01T17:19:58+08:00"
        }]
}
```

























