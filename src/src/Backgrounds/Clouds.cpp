#include "Backgrounds/Clouds.h"

Clouds::Clouds(){
    float l1h = 63;
	float l2h = 94;
	float l3h = 117;
	float l4h = 151;

	auto layer1 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer1->Draw_Src(0.0f, 0.0f, 320.0f, l1h);
	layer1->Draw_Dst(0.0f, 240.0f - l1h);
	layer1->Draw_Siz(320.0f, l1h);

	auto layer2 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer2->Draw_Src(0.0f, 63.0f, 320.0f, l2h);
	layer2->Draw_Dst(0.0f, 240.0f - l2h);
	layer2->Draw_Siz(320.0f, l2h);

	auto layer3 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer3->Draw_Src(0.0f, 157.0f, 320.0f, l3h);
	layer3->Draw_Dst(0.0f, 240.0f - l3h);
	layer3->Draw_Siz(320.0f, l3h);

	auto layer4 = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer4->Draw_Src(0.0f, 274.0f, 320.0f, l4h);
	layer4->Draw_Dst(0.0f, 240.0f - l4h);
	layer4->Draw_Siz(320.0f, l4h);

	auto layer1_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer1_c->Draw_Src(0.0f, 0.0f, 320.0f, l1h);
	layer1_c->Draw_Dst(320.0f, 240.0f - l1h);
	layer1_c->Draw_Siz(320.0f, l1h);

	auto layer2_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer2_c->Draw_Src(0.0f, 63.0f, 320.0f, l2h);
	layer2_c->Draw_Dst(320.0f, 240.0f - l2h);
	layer2_c->Draw_Siz(320.0f, l2h);

	auto layer3_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer3_c->Draw_Src(0.0f, 157.0f, 320.0f, l3h);
	layer3_c->Draw_Dst(320.0f, 240.0f - l3h);
	layer3_c->Draw_Siz(320.0f, l3h);

	auto layer4_c = std::make_unique<Sprite>("assets/img/stg_story_bgs.bmp");
	layer4_c->Draw_Src(0.0f, 274.0f, 320.0f, l4h);
	layer4_c->Draw_Dst(320.0f, 240.0f - l4h);
	layer4_c->Draw_Siz(320.0f, l4h);

	cloudsBG.push_back(std::move(layer4_c));
	cloudsBG.push_back(std::move(layer4));
	cloudsBG.push_back(std::move(layer3_c));
	cloudsBG.push_back(std::move(layer3));
	cloudsBG.push_back(std::move(layer2_c));
	cloudsBG.push_back(std::move(layer2));
	cloudsBG.push_back(std::move(layer1_c));
	cloudsBG.push_back(std::move(layer1));
}

Clouds::~Clouds(){
    for(size_t i = 0; i < cloudsBG.size(); i++){
        cloudsBG[i].reset();
    }
    
}

void Clouds::Update(double dt){
    for (size_t i = 0; i < cloudsBG.size(); i++) {
		int x = i / 2;
		cloudsBG[i]->m_dst.x -= (moon_speeds[x] * dt);

		if (cloudsBG[i]->m_dst.x <= -GameDefs::WindowWidth) cloudsBG[i]->m_dst.x += GameDefs::WindowWidth*2;
	}
}

void Clouds::Render(){
    for (size_t i = 0; i < cloudsBG.size(); i++) {
		cloudsBG[i]->Render();
	}
}