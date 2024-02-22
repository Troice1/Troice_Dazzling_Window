#pragma once


#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include <iostream>

#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))


namespace Var {
    int ColorNumber = 1;
    int count = 0;
}

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::BeginItemTooltip())
    {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}


void MainWindow() {
    static float f = 0.0f;
    static int counter = 0;
    static bool open = true;

    static float color_number = 50.0f;

    if (open) {
        ImGui::Begin("Troice Dazzling Window", &open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::SetWindowSize(ImVec2(600, 350));

        ImGuiStyle& style = ImGui::GetStyle();

        style.FrameRounding = 10.0f;

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;

        ImGui::SetCursorPos({ 10.0f, 30.0f });
        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
        ImGui::BeginChild("ChildR", ImVec2(115, 260), true, window_flags);
        if (ImGui::BeginTable("split", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings))
        {
            ImGui::TableNextColumn();

            float Btn_Pos_Y = 10.0f;
            ImGui::SetCursorPos({ 10.0f, Btn_Pos_Y });
            ImGui::PushStyleColor(ImGuiCol_Button, Var::ColorNumber == 1 ? ImVec4(1.0f, 0.5f, 0.3f, 1.0f) : ImVec4(0.35f, 0.00f, 1.00f, 0.50f));
            if (ImGui::Button("Home", ImVec2(90, 30))) {
                Var::ColorNumber = 1;
            }
            ImGui::PopStyleColor();


            Btn_Pos_Y += 40.0f;
            ImGui::SetCursorPos({ 10.0f, Btn_Pos_Y });
            ImGui::PushStyleColor(ImGuiCol_Button, Var::ColorNumber == 2 ? ImVec4(1.0f, 0.5f, 0.3f, 1.0f) : ImVec4(0.35f, 0.00f, 1.00f, 0.50f));
            if (ImGui::Button("Button", ImVec2(90, 30))) {
                Var::ColorNumber = 2;
            }
            ImGui::PopStyleColor();


            Btn_Pos_Y += 40.0f;
            ImGui::SetCursorPos({ 10.0f, Btn_Pos_Y });
            ImGui::PushStyleColor(ImGuiCol_Button, Var::ColorNumber == 3 ? ImVec4(1.0f, 0.5f, 0.3f, 1.0f) : ImVec4(0.35f, 0.00f, 1.00f, 0.50f));
            if (ImGui::Button("CheckBox", ImVec2(90, 30))) {
                Var::ColorNumber = 3;
            }
            ImGui::PopStyleColor();


            Btn_Pos_Y += 40.0f;
            ImGui::SetCursorPos({ 10.0f, Btn_Pos_Y });
            ImGui::PushStyleColor(ImGuiCol_Button, Var::ColorNumber == 4 ? ImVec4(1.0f, 0.5f, 0.3f, 1.0f) : ImVec4(0.35f, 0.00f, 1.00f, 0.50f));
            if (ImGui::Button("Slide", ImVec2(90, 30))) {
                Var::ColorNumber = 4;
            }
            ImGui::PopStyleColor();


            Btn_Pos_Y += 40.0f;
            ImGui::SetCursorPos({ 10.0f, Btn_Pos_Y });
            ImGui::PushStyleColor(ImGuiCol_Button, Var::ColorNumber == 5 ? ImVec4(1.0f, 0.5f, 0.3f, 1.0f) : ImVec4(0.35f, 0.00f, 1.00f, 0.50f));
            if (ImGui::Button("Plot", ImVec2(90, 30))) {
                Var::ColorNumber = 5;
            }
            ImGui::PopStyleColor();


            Btn_Pos_Y += 40.0f;
            ImGui::SetCursorPos({ 10.0f, Btn_Pos_Y });
            ImGui::PushStyleColor(ImGuiCol_Button, Var::ColorNumber == 6 ? ImVec4(1.0f, 0.5f, 0.3f, 1.0f) : ImVec4(0.35f, 0.00f, 1.00f, 0.50f));
            if (ImGui::Button("Execl", ImVec2(90, 30))) {
                Var::ColorNumber = 6;
            }
            ImGui::PopStyleColor();

            ImGui::EndTable();
        }
        ImGui::EndChild();
        ImGui::PopStyleVar();


        ImGui::SetCursorPos({ 130.0f, 30.0f });
        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
        ImGui::BeginChild("Content", ImVec2(450, 260), true, window_flags);
        if (ImGui::BeginTable("split_1", 1, ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings))
        {
            ImGui::TableNextColumn();

            if (Var::ColorNumber == 1) {
                ImGui::Text("Hello,I am Troice.");
                ImGui::Text("As you can see, this is a window.");
                ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.3f, 1.0f), "It is developed in C++language, based on a pure \nIMGUI framework.");
                ImGui::NewLine();
                ImGui::TextColored(ImVec4(0.5f, 0.0f, 1.0f, 1.0f), "Developer:Troice   QQ:2133351499.");
            }
            else if (Var::ColorNumber == 2) {
                for (int i = 0; i < 7; i++)
                {
                    if (i > 0)
                        ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.7f));
                    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.8f, 0.8f));
                    ImGui::Button("Click");
                    ImGui::PopStyleColor(3);
                    ImGui::PopID();
                }

                ImGui::NewLine();

                ImVec2 sz = ImVec2(-FLT_MIN, 0.0f);
                ImGui::Button("Long Button 1", sz);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_ForTooltip))
                    ImGui::SetTooltip("I am Long Button 1");

                ImGui::Button("Long Button 2", sz);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNone))
                    ImGui::SetTooltip("I am Long Button 2");

                ImGui::Button("Long Button 3", sz);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort | ImGuiHoveredFlags_NoSharedDelay))
                    ImGui::SetTooltip("I am Long Button 3", ImGui::GetStyle().HoverDelayShort);

                ImGui::Button("Long Button 4", sz);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal | ImGuiHoveredFlags_NoSharedDelay))
                    ImGui::SetTooltip("I am Long Button 4)", ImGui::GetStyle().HoverDelayNormal);

                ImGui::Button("Long Button 5", sz);
                if (ImGui::IsItemHovered(ImGuiHoveredFlags_Stationary))
                    ImGui::SetTooltip("I am Long Button 5");


                ImGui::NewLine();
                for (int i = 0; i < 5; i++) {
                    ImGui::Button("MainButton");
                    ImGui::SameLine();
                }
                ImGui::NewLine();
                if (ImGui::Button("Button")) {
                    Var::count += 1;
                }
                for (int i = 0; i < Var::count; i++) {
                    ImGui::Button("New Button");
                    // ImGui::SameLine();
                }

            }
            else if (Var::ColorNumber == 3) {
                static bool checkOne = false;
                static bool checkTwo = true;
                static bool checkThree = false;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (i == 0) {
                            ImGui::Checkbox("CheckBox", &checkOne);
                        }
                        else if (i == 1) {
                            ImGui::Checkbox("CheckBox1", &checkTwo);
                        }
                        else {
                            ImGui::Checkbox("CheckBox2", &checkThree);
                        }
                        ImGui::SameLine();

                    }
                    ImGui::NewLine();
                }
                static bool checkMain = false;
                ImGui::Checkbox("MainCheckBox", &checkMain);
            }
            else if (Var::ColorNumber == 4) {
                const float spacing = 4;
                ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(spacing, spacing));

                static int int_value = 0;
                ImGui::VSliderInt("##int", ImVec2(18, 160), &int_value, 0, 5);
                ImGui::SameLine();

                static float values[7] = { 0.0f, 0.60f, 0.35f, 0.9f, 0.70f, 0.20f, 0.0f };
                ImGui::PushID("set1");
                for (int i = 0; i < 7; i++)
                {
                    if (i > 0) ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor::HSV(i / 7.0f, 0.5f, 0.5f));
                    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.5f));
                    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.5f));
                    ImGui::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor::HSV(i / 7.0f, 0.9f, 0.9f));
                    ImGui::VSliderFloat("##v", ImVec2(18, 160), &values[i], 0.0f, 1.0f, "");
                    if (ImGui::IsItemActive() || ImGui::IsItemHovered())
                        ImGui::SetTooltip("%.3f", values[i]);
                    ImGui::PopStyleColor(4);
                    ImGui::PopID();
                }
                ImGui::PopID();

                ImGui::SameLine();
                ImGui::PushID("set2");
                static float values2[4] = { 0.20f, 0.80f, 0.40f, 0.25f };
                const int rows = 3;
                const ImVec2 small_slider_size(18, (float)(int)((160.0f - (rows - 1) * spacing) / rows));
                for (int nx = 0; nx < 4; nx++)
                {
                    if (nx > 0) ImGui::SameLine();
                    ImGui::BeginGroup();
                    for (int ny = 0; ny < rows; ny++)
                    {
                        ImGui::PushID(nx * rows + ny);
                        ImGui::VSliderFloat("##v", small_slider_size, &values2[nx], 0.0f, 1.0f, "");
                        if (ImGui::IsItemActive() || ImGui::IsItemHovered())
                            ImGui::SetTooltip("%.3f", values2[nx]);
                        ImGui::PopID();
                    }
                    ImGui::EndGroup();
                }
                ImGui::PopID();

                ImGui::SameLine();
                ImGui::PushID("set3");
                for (int i = 0; i < 4; i++)
                {
                    if (i > 0) ImGui::SameLine();
                    ImGui::PushID(i);
                    ImGui::PushStyleVar(ImGuiStyleVar_GrabMinSize, 40);
                    ImGui::VSliderFloat("##v", ImVec2(40, 160), &values[i], 0.0f, 1.0f, "%.2f\nsec");
                    ImGui::PopStyleVar();
                    ImGui::PopID();
                }
                ImGui::PopID();
                ImGui::PopStyleVar();
            }
            else if (Var::ColorNumber == 5) {
                {
                    static bool animate = true;
                    ImGui::Checkbox("Animate", &animate);

                    static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
                    ImGui::PlotLines("Frame Times", arr, IM_ARRAYSIZE(arr));
                    ImGui::PlotHistogram("Histogram", arr, IM_ARRAYSIZE(arr), 0, NULL, 0.0f, 1.0f, ImVec2(0, 80.0f));

                    static float values[90] = {};
                    static int values_offset = 0;
                    static double refresh_time = 0.0;
                    if (!animate || refresh_time == 0.0)
                        refresh_time = ImGui::GetTime();
                    while (refresh_time < ImGui::GetTime())
                    {
                        static float phase = 0.0f;
                        values[values_offset] = cosf(phase);
                        values_offset = (values_offset + 1) % IM_ARRAYSIZE(values);
                        phase += 0.10f * values_offset;
                        refresh_time += 1.0f / 60.0f;
                    }

                    {
                        float average = 0.0f;
                        for (int n = 0; n < IM_ARRAYSIZE(values); n++)
                            average += values[n];
                        average /= (float)IM_ARRAYSIZE(values);
                        char overlay[32];
                        sprintf_s(overlay, "avg %f", average);
                        ImGui::PlotLines("Lines", values, IM_ARRAYSIZE(values), values_offset, overlay, -1.0f, 1.0f, ImVec2(0, 80.0f));
                    }

                    struct Funcs
                    {
                        static float Sin(void*, int i) { return sinf(i * 0.1f); }
                        static float Saw(void*, int i) { return (i & 1) ? 1.0f : -1.0f; }
                    };
                    static int func_type = 0, display_count = 70;
                    ImGui::SeparatorText("Functions");
                    ImGui::SetNextItemWidth(ImGui::GetFontSize() * 8);
                    ImGui::Combo("func", &func_type, "Sin\0Saw\0");
                    ImGui::SameLine();
                    ImGui::SliderInt("Sample count", &display_count, 1, 400);
                    float (*func)(void*, int) = (func_type == 0) ? Funcs::Sin : Funcs::Saw;
                    ImGui::PlotLines("Lines", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
                    ImGui::PlotHistogram("Histogram", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
                    ImGui::Separator();

                    static float progress = 0.0f, progress_dir = 1.0f;
                    if (animate)
                    {
                        progress += progress_dir * 0.4f * ImGui::GetIO().DeltaTime;
                        if (progress >= +1.1f) { progress = +1.1f; progress_dir *= -1.0f; }
                        if (progress <= -0.1f) { progress = -0.1f; progress_dir *= -1.0f; }
                    }

                    ImGui::ProgressBar(progress, ImVec2(0.0f, 0.0f));
                    ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x);
                    ImGui::Text("Progress Bar");

                    float progress_saturated = IM_CLAMP(progress, 0.0f, 1.0f);
                    char buf[32];
                    sprintf_s(buf, "%d/%d", (int)(progress_saturated * 1753), 1753);
                    ImGui::ProgressBar(progress, ImVec2(0.f, 0.f), buf);
                }
            }
            else if (Var::ColorNumber == 6) {
                static ImGuiTableFlags flags = ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_Borders | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_NoSavedSettings;

                for (int n = 0; n < 3; n++)
                {
                    char buf[32];
                    sprintf_s(buf, "Synced Table %d", n);
                    bool open = ImGui::CollapsingHeader(buf, ImGuiTreeNodeFlags_DefaultOpen);
                    if (open && ImGui::BeginTable("Table", 3, flags, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 5)))
                    {
                        ImGui::TableSetupColumn("One");
                        ImGui::TableSetupColumn("Two");
                        ImGui::TableSetupColumn("Three");
                        ImGui::TableHeadersRow();
                        const int cell_count = (n == 1) ? 27 : 9;
                        for (int cell = 0; cell < cell_count; cell++)
                        {
                            ImGui::TableNextColumn();
                            ImGui::Text("this cell %d", cell);
                        }
                        ImGui::EndTable();
                    }
                }
            }


            ImGui::EndTable();
        }
        ImGui::EndChild();
        ImGui::PopStyleVar();

        ImGui::NewLine();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

        ImGui::TextColored(ImVec4(0.5f, 0.0f, 1.0f, 1.0f), "Developer:Troice   QQ:2133351499.");
        ImGui::SameLine();
        HelpMarker("Author's Information");


        ImGui::End();
    }
    else {
        exit(0);
    }
    
}