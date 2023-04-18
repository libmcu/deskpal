![gif](/deskpal.gif)

매 30분마다 공기질 정보와 원-달러 환율을 업데이트합니다. 업데이트 주기는 [`COLLECTOR_SCAN_INTERVAL_MS`](https://github.com/libmcu/deskpal/blob/main/include/collector.h#L26)에서 변경할 수 있습니다.

| Good   | Moderate | Unhealthy for Sensitive Groups | Unhealthy | Very Unhealthy | Hazardous |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 - 50 | 51 - 100 | 101 - 150 | 151 - 200 | 201 - 300 | 300+  |
| ![](https://cdn-icons-png.flaticon.com/512/98/98233.png) | ![](https://cdn-icons-png.flaticon.com/512/3271/3271004.png) | ![](https://cdn-icons-png.flaticon.com/512/7219/7219129.png) | ![](https://cdn-icons-png.flaticon.com/512/2773/2773916.png) | ![](https://cdn-icons-png.flaticon.com/512/7445/7445242.png) | ![](https://cdn-icons-png.flaticon.com/512/4879/4879598.png) |
| <a href="https://www.flaticon.com/free-icons/shine" title="shine icons">Shine icons created by Freepik - Flaticon</a> | <a href="https://www.flaticon.com/free-icons/leisure" title="leisure icons">Leisure icons created by Freepik - Flaticon</a> |<a href="https://www.flaticon.com/free-icons/air-pollution" title="air pollution icons">Air pollution icons created by Freepik - Flaticon</a> | <a href="https://www.flaticon.com/free-icons/pollution" title="pollution icons">Pollution icons created by Freepik - Flaticon</a> | <a href="https://www.flaticon.com/free-icons/gas-mask" title="gas mask icons">Gas mask icons created by Umeicon - Flaticon</a> | <a href="https://www.flaticon.com/free-icons/skull" title="skull icons">Skull icons created by Triangle Squad - Flaticon</a> |

## How to build your own
### 하드웨어 모듈
- [ESP32S3 MADI board](https://libmcu.org/kr/madi)
- [1.54" E-Ink display module](https://www.waveshare.com/1.54inch-e-paper-module.htm)

### 핀 연결

| EPD  | MADI     |
| ---- | -------- |
| BUSY | 6(IO2)   |
| RST  | 8(IO38)  |
| DC   | 7(IO37)  |
| CS   | 14(IO10) |
| CLK  | 16(IO12) |
| DIN  | 15(IO11) |
| GND  | 2(GND)   |
| 3.3V | 1(3V3)   |

### 공기질 정보 토큰 입력
AQI 정보는 [aqicn.org](https://aqicn.org/)에서 받아옵니다.
따라서 [토큰 발행 페이지](https://aqicn.org/data-platform/token/)에서 먼저 토큰을 발급받아야 합니다.

발급받은 토큰을 [`AQI_URL`](https://github.com/libmcu/deskpal/blob/main/src/collector.c#L17)에 입력합니다.

`#define AQI_TOKEN	"{Your token}"`

### 와이파이 정보 입력
1. [`DEFAULT_SSID`](https://github.com/libmcu/deskpal/blob/main/src/collector.c#L14)에 SSID를 입력합니다.
2. [`DEFAULT_PASS`](https://github.com/libmcu/deskpal/blob/main/src/collector.c#L15)에 비밀번호를 입력합니다.

```c
#define DEFAULT_SSID	"Your SSID"
#define DEFAULT_PASS	"Your password"
```

### 빌드 및 다운로드
마디 보드의 [영상 가이드](https://www.youtube.com/playlist?list=PLhdIB9v89ue2Gs9KZNzTYOf4VMgF81Le3)나 [문서](https://docs.libmcu.org)를 참고하세요.
