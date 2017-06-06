#pragma once

#include "Config.h"
#include "Scene.h"
#include "ScriptResource.h"
#include "SusAnalyzer.h"
#include "SoundManager.h"

#define SU_IF_SCENE_PLAYER "ScenePlayer"

// Sceneという名前こそついてるけど挙動は別物
// SceneManagerに追加されない

class ScenePlayer : public Scene {
protected:
    int reference = 0;
    int hGroundBuffer;
    int hAirBuffer;
    std::vector<SusDrawableNoteData> data;
    std::map<std::string, SResource*> resources;
    SoundStream *bgmStream;
    int seenObjects = 0;

public:
    void AddRef();
    void Release();

    void Initialize() override;
    void SetPlayerResource(const std::string &name, SResource *resource);
    void Draw() override;
    bool IsDead() override;
    void Finalize();

    void Play();
    double GetPlayingTime();
    int GetSeenObjectsCount();
};

class ExecutionManager;
void RegisterPlayerScene(ExecutionManager *exm);