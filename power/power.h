/*
 * Copyright (C) 2016 The CyanogenMod Project <http://www.cyanogenmod.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define MS_TO_NS (1000000L)

enum {
    PROFILE_POWER_SAVE = 0,
    PROFILE_BALANCED,
    PROFILE_PERFORMANCE,
    PROFILE_MAX
};

typedef struct governor_settings {
    // max/min freqs (-1 for default)
    int max_freq;
    int min_freq;
    // load at which to start scaling up
    int up_threshold;
    // higher down_differential == slower downscaling
    int down_differential;
    // wait sampling_rate * cpu_down_rate us before trying to downscale
    int cpu_down_rate;
    int sampling_rate; // in microseconds
    int io_is_busy;
    // boosting
    int boost_freq;
    int boost_mincpus;
    long interaction_boost_time;
} power_profile;

static power_profile profiles[PROFILE_MAX] = {
    [PROFILE_POWER_SAVE] = {
        .max_freq = 1000000,
        .min_freq = -1,
        .up_threshold = 95,
        .down_differential = 5,
        .sampling_rate = 100000,
        .io_is_busy = 0,
    },
    [PROFILE_BALANCED] = {
        .max_freq = -1,
        .min_freq = -1,
        .up_threshold = 85,
        .down_differential = 5,
        .sampling_rate = 100000,
        .io_is_busy = 0,
    },
    [PROFILE_PERFORMANCE] = {
        .min_freq = -1,
        .max_freq = -1,
        .up_threshold = 75,
        .down_differential = 5,
        .sampling_rate = 100000,
        .io_is_busy = 1,
    },
};

static power_profile profiles_low_power[PROFILE_MAX] = {
    [PROFILE_POWER_SAVE] = {
        .max_freq = 1000000,
        .min_freq = -1,
        .up_threshold = 95,
        .down_differential = 5,
        .sampling_rate = 100000,
        .io_is_busy = 0,
    },
    [PROFILE_BALANCED] = {
        .max_freq = -1,
        .min_freq = -1,
        .up_threshold = 85,
        .down_differential = 5,
        .sampling_rate = 100000,
        .io_is_busy = 0,
    },
    [PROFILE_PERFORMANCE] = {
        .min_freq = -1,
        .max_freq = -1,
        .up_threshold = 75,
        .down_differential = 5,
        .sampling_rate = 100000,
        .io_is_busy = 1,
    },
};

