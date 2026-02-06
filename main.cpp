#include <imgui.h>

static void RenderSidebar() {
    ImGui::BeginChild("Sidebar", ImVec2(64.0f, 0.0f), false);
    ImGui::Spacing();
    for (int i = 0; i < 5; ++i) {
        ImGui::PushID(i);
        ImGui::Button(" ", ImVec2(38.0f, 38.0f));
        ImGui::Spacing();
        ImGui::PopID();
    }
    ImGui::EndChild();
}

static void RenderAimbotSection() {
    ImGui::TextUnformatted("Aimbot");
    ImGui::Separator();
    static bool enableAimbot = true;
    static int targetHitbox = 0;
    static float smoothness = 0.0f;
    static float fovRange = 50.0f;
    static bool drawFov = false;
    static bool useFov = true;
    static bool closestEnemy = false;

    ImGui::Checkbox("Enable Aimbot", &enableAimbot);
    ImGui::TextUnformatted("Aimbot Key: None");

    const char *hitboxOptions[] = {"Head", "Neck", "Chest"};
    ImGui::Combo("Target Hitbox", &targetHitbox, hitboxOptions, IM_ARRAYSIZE(hitboxOptions));

    ImGui::SliderFloat("Smoothness", &smoothness, 0.0f, 100.0f, "%.0f");
    ImGui::SliderFloat("FOV Range", &fovRange, 0.0f, 100.0f, "%.0f");

    ImGui::Checkbox("Draw FOV Circle", &drawFov);
    ImGui::Checkbox("Use FOV", &useFov);
    ImGui::Checkbox("Closest Enemy", &closestEnemy);
}

static void RenderFiltersSection() {
    ImGui::TextUnformatted("Filters & Targets");
    ImGui::Separator();

    static bool ignoreTeam = false;
    static bool ignoreDowned = false;
    static bool ignoreBots = false;
    static bool visibleOnly = false;
    static bool silentAim = false;
    static bool target360 = false;

    ImGui::Checkbox("Ignore Team", &ignoreTeam);
    ImGui::Checkbox("Ignore Downed", &ignoreDowned);
    ImGui::Checkbox("Ignore Training Bots", &ignoreBots);
    ImGui::Checkbox("Visible Only", &visibleOnly);
    ImGui::Separator();
    ImGui::Checkbox("Silent Aim", &silentAim);
    ImGui::Checkbox("Target 360", &target360);
}

void RenderUpakulUI() {
    ImGui::SetNextWindowSize(ImVec2(880.0f, 520.0f), ImGuiCond_Always);
    ImGui::Begin("Upakul", nullptr,
                 ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
                     ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar);

    ImGui::Columns(2, nullptr, false);
    ImGui::SetColumnWidth(0, 70.0f);
    RenderSidebar();
    ImGui::NextColumn();

    ImGui::TextUnformatted("Upakul");
    ImGui::Spacing();

    ImGui::Columns(2, "MainSections", false);
    RenderAimbotSection();
    ImGui::NextColumn();
    RenderFiltersSection();
    ImGui::Columns(1);

    ImGui::End();
}
