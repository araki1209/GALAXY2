#include "CONTAINER.h"
#include"libOne.h"
void CONTAINER::load() {
	setData();
}
void CONTAINER::setData() {
	//背景
	Data.back_img.normalColor = COLOR(255, 255, 255);
	//タイトル
	Data.title.backColor = COLOR(0, 0, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.textSize = 300;
	Data.title.pos.x = 0;
	Data.title.pos.y = 300;
	Data.title.p_data = 0;

	//ステージ
	Data.stage1.no = 2;

	Data.game_clear.pos.x = 0;
	Data.game_clear.pos.y = 0;


	//トランジション
	Data.transition_fade.color = COLOR(0, 0, 0);
	Data.transition_fade.color.a = 255;
	Data.transition_fade.pos1.x = 0;
	Data.transition_fade.pos1.y = 0;
	Data.transition_fade.pos2.x = width;
	Data.transition_fade.pos2.y = height;
	Data.transition_fade.colorMode = 255;
	Data.transition_fade.time = 2.0f;

	//プレイヤー
	Data.player.angle = 0;
	Data.player.pos.x = 960;
	Data.player.pos.y = 970;
	Data.player.phW = 35;
	Data.player.phH = 25;
	Data.player.advSpeed = 500;
	Data.player.launchVec = VECTOR2(0, -1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.05f;
	Data.player.ofsLaunchDist = 50;
	Data.player.bcRadius = 40;
	Data.player.invincibleRestTime = 0;
	Data.player.invincibleTime = 0.05f;
	Data.player.hp = 5;
	Data.player.hpGaugeOfst = VECTOR2(0, -120);
	Data.player.collisionColor = COLOR(255, 0, 0);
	Data.player.normalColor = COLOR(255, 255, 255);

	Data.player2.angle = 0;
	Data.player2.pos.x = 960;
	Data.player2.pos.y = 970;
	Data.player2.phW = 35;
	Data.player2.phH = 25;
	Data.player2.advSpeed = 500;
	Data.player2.launchVec = VECTOR2(0, -1);
	Data.player2.triggerErapsedTime = 0;
	Data.player2.triggerInterval = 0.05f;
	Data.player2.ofsLaunchDist = 50;
	Data.player2.bcRadius = 40;
	Data.player2.invincibleRestTime = 0;
	Data.player2.invincibleTime = 0.05f;
	Data.player2.hp = 5;
	Data.player2.hpGaugeOfst = VECTOR2(0, -120);
	Data.player2.collisionColor = COLOR(255, 0, 0);
	Data.player2.normalColor = COLOR(255, 255, 255);

	//エネミー
	Data.enemyM.totalNum = 1;
	//楕円
	Data.enemyM.majRadius = 800;
	Data.enemyM.minRadius = 100;
	Data.enemyM.cenPos.x = width / 2;
	Data.enemyM.cenPos.y = -300;
	Data.enemyM.fallSpeed = 60;
	Data.enemyM.targetPosY = 200;
	Data.enemyM.refTheta = 0;
	Data.enemyM.refThetaSpeed = 0.6f;

	Data.enemyM.curNum = Data.enemyM.totalNum;
	Data.enemyM.advSpeed = 100;
	Data.enemyM.arrivalY = 300;
	Data.enemyM.ThetaSpeed = 0.6f;
	Data.enemyM.invincibleTime = 0.05f;
	Data.enemyM.refWidth = 0;
	Data.enemyM.ofsLaunchDist= 25;
	Data.enemyM.triggerInterval = 0.74f;
	Data.enemyM.initHp = 5;
	Data.enemyM.hpGaugeOfst = VECTOR2(0, -120);
	Data.enemyM.collisionColor = COLOR(255, 0, 0);
	Data.enemyM.normalColor = COLOR(255, 255, 255);

	Data.enemyB.totalNum = 3;
	Data.enemyB.curNum = Data.enemyB.totalNum;
	Data.enemyB.cenPos.x = 0;
	Data.enemyB.cenPos.y = 100;
	Data.enemyB.advSpeed = 100;
	Data.enemyB.invincibleTime = 0.05f;
	Data.enemyB.refWidth = 0;
	Data.enemyB.ofsLaunch = 25;
	Data.enemyB.limX = 600;

	Data.enemyB.ofsLaunchDist = 100;
	Data.enemyB.triggerInterval = 0.74f;
	Data.enemyB.bcRadius = 40;

	Data.enemyB.invincibleTime = 0.05f;
	Data.enemyB.initHp = 5;
	Data.enemyB.hpGaugeOfst = VECTOR2(0, -120);
	Data.enemyB.collisionColor = COLOR(255, 0, 0);
	Data.enemyB.normalColor = COLOR(255, 255, 255);
	//ボス
	Data.boss.totalNum = 1;
	Data.boss.curNum = Data.boss.totalNum;
	Data.boss.cenPos.x = width / 2;
	Data.boss.cenPos.y = 100;
	Data.boss.advSpeedX = 500;
	Data.boss.advSpeedY = 200;
	Data.boss.triggerInterval = 0.74;
	Data.boss.ofstLaunchDist = 100;
	
	Data.boss.bcRadius = 40;
	Data.boss.invincibleTime = 0.05f;
	Data.boss.initHp = 20;
	Data.boss.hpGaugeOfst = (0, 100);
	Data.boss.collisionColor = (255, 0, 0);
	Data.boss.normalColor = (255, 255, 255);

	//プレイヤーの弾
	Data.playerBullet.totalNum = 100;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 600;
	Data.playerBullet.angSpeed = 0;
	Data.playerBullet.bRadius = 20;

	//エネミーの弾
	Data.enemyMBullet.totalNum = 20;
	Data.enemyMBullet.curNum = 0;
	Data.enemyMBullet.advSpeed = 600;
	Data.enemyMBullet.angSpeed = 0;
	Data.enemyMBullet.bRadius = 20;

	//HPゲージ
	Data.hpGauge.coWidth = 30;
	Data.hpGauge.hi = 15;
	Data.hpGauge.safeColor = COLOR(0, 255, 0);
	Data.hpGauge.dangerColor = COLOR(255, 0, 0);
}
void CONTAINER::loadGraphics() {
	//背景
	Data.back_img.img1 = loadImage("assets\\s1.png");
	Data.back_img.img2 = loadImage("assets\\s2.png");
	Data.back_img.img3 = loadImage("assets\\s3.png");

	//シーケンス移行
	Data.title.img = loadImage("assets\\haikei.png");
	//Data.game_clear.img = loadImage("assets\\clear.jpg");
	Data.player.img = loadImage("assets\\kitai1.png");
	Data.player2.img = loadImage("assets\\a.png");

	//プレイヤー
	Data.playerBullet.img = loadImage("assets\\9.png");
	//エネミー
	Data.enemyM.img = loadImage("assets\\hjh.png");
	Data.enemyMBullet.img = loadImage("assets\\12.png");
	Data.enemyB.img = loadImage("assets\\adf.png");
	Data.boss.img = loadImage("assets\\boss.png");


}