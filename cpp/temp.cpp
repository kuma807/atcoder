int counter = 0;
void loop() {
  sws[0] = digitalRead(19);
  //スイッチがついてるなら
  if (sws[0]) {
    //表示をクリアする
    for (i = 1; i < 8; i++) {
      digitalWrite(i, LOW);
    }

    if (counter == 0) {
      //0の表示をする
      for (i = 1; i < 7; ++i) {
        digitalWrite(i, HIGH);
      }
      counter = 1;
    }
    else if (counter == 1) {
      //1の表示をする
      for (i = 2; i < 4; ++i) {
        digitalWrite(i, HIGH);
      }
      counter = 2;
    }
    else if (counter == 2) {
      //2の表示をする
      for (i = 1; i < 8; ++i) {
        digitalWrite(i, HIGH);
      }
      for (ll i = 1; i < 3; ++i) {
        digitalWrite(i * 3, LOW);
      }
      counter = 0;
    }
  }
}
