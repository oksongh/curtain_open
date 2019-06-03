仕様
  やりたいこと
    wifiで時刻を設定してその時刻になったらカーテンを開ける
    ボタンを押すとカーテンが開閉する

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


    現在時刻(hh:mm) = 基準時刻(hh:mm)+(現在時刻RTC(min)-基準時刻のとき取得したRTC(min))/60h+%

    タスクスーパークラス
    loop:現在時刻が予約された時刻になったか ->yes state=getstate
                                      ->no 何もしない
    init(){

      set_time()
      set_output()
    }
    set_time(kijunn,yoyaku)
    get_state()

    output_state
    open()
    close()
    buzzer()

    vertual set_output()
    -
    子クラス

    @override
    set_output()
      open...などする仕事ごとにクラスを作る
    カーテン開ける&＆ブザー鳴らす
    カーテン開ける
    カーテン閉める
    カーテン閉める&＆ブザー鳴らす

  必要なもの
    esp32
    button 2個
    motor
    プーリー
    ひも
