매 30분마다 공기질 정보와 원-달러 환율을 업데이트합니다. 업데이트 주기는 [`COLLECTOR_SCAN_INTERVAL_MS`](https://github.com/libmcu/deskpal/blob/594c5070e11e0e1fa31d0c404874cd45880dd0e2/include/collector.h#L26)에서 변경할 수 있습니다.

| Good   | Moderate | Unhealthy for<br/>Sensitive Groups | Unhealthy | Very Unhealthy | Hazardous |
| :---: | :---: | :---: | :---: | :---: | :---: |
| ![]()  | ![]()    | ![]()     | ![]()     | ![]()     | ![]() |
| 0 - 50 | 51 - 100 | 101 - 150 | 151 - 200 | 201 - 300 | 300+  |

## 공기질 정보 토큰 입력
AQI 데이터는 [aqicn.org](https://aqicn.org/)를 사용합니다.
따라서 [토큰 발행 페이지](https://aqicn.org/data-platform/token/)에서 먼저 토큰을 발급받아야 합니다.

발급받은 토큰을 [`AQI_URL`](https://github.com/libmcu/deskpal/blob/594c5070e11e0e1fa31d0c404874cd45880dd0e2/src/collector.c#L17)에 입력합니다.

`#define AQI_URL			"https://api.waqi.info/feed/@4497/?token={Your token}"`

## 와이파이 정보 입력
1. [`DEFAULT_SSID`](https://github.com/libmcu/deskpal/blob/594c5070e11e0e1fa31d0c404874cd45880dd0e2/src/collector.c#L14)에 SSID를 입력합니다.
2. [`DEFAULT_PASS`](https://github.com/libmcu/deskpal/blob/594c5070e11e0e1fa31d0c404874cd45880dd0e2/src/collector.c#L15)에 비밀번호를 입력합니다.

```c
#define DEFAULT_SSID		"Your SSID"
#define DEFAULT_PASS		"Your password"
```
