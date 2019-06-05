仕様
  やりたいこと
    wifiで時刻を設定してその時刻になったらカーテンを開ける
    ボタンを押すとカーテンが開閉する

    button押す->open -> state = open
               close -> state = close

  プログラム
    wifiでデータを受け取る

    パース

    データによってやることを変える
    open -> 開ける
    close -> 閉める
    reserve -> 予約する

    開ける->出力をopenにする
    閉める->出力をcloseにする
    予約する->open 時刻 buzzerのオンオフ(bool)　タスクスーパークラス作る<-基準時刻(hh:mm),予約時刻(hh:mm)
            close 時刻 buzzerのオンオフ(bool)


    現在時刻(hh:mm) = 基準時刻(hh:mm)+(現在時刻millis(min)-基準時刻のとき取得したmillis(min))/60h+%

    タスククラス
    loop:現在時刻が予約された時刻になったか ->yes state=getstate
                                      ->no 何もしない
    現在時刻hour mim


    init(){

      set_time()
      set_output()
    }
    loop(){

    }
    set_time(kijunn,yoyaku)
    get_state(){return output_state}

    output_state
    open()
    close()
    buzzer()

    カーテン開ける&＆ブザー鳴らす
    カーテン開ける
    カーテン閉める
    カーテン閉める&＆ブザー鳴らす

    time_handlerクラス
    long nowRTC(){

    }
    <!-- get_now_by_mills(){
      long
      millis()/(1000*60)

    } -->


  必要なもの
    esp32
    button 2個
    motor
    プーリー
    ひも
