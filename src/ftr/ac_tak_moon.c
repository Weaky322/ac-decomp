extern cKF_Skeleton_R_c cKF_bs_r_int_tak_moon;
extern cKF_Animation_R_c cKF_ba_r_int_tak_moon;

static void fTMN_ct(FTR_ACTOR* ftr_actor, u8* data) {
    cKF_SkeletonInfo_R_c* keyframe = &ftr_actor->keyframe;
    int min = Common_Get(time.rtc_time.min);
    int sec = Common_Get(time.rtc_time.sec);

    cKF_SkeletonInfo_R_ct(keyframe, &cKF_bs_r_int_tak_moon, &cKF_ba_r_int_tak_moon, ftr_actor->joint, ftr_actor->morph);
    cKF_SkeletonInfo_R_init_standard_repeat(keyframe, &cKF_ba_r_int_tak_moon, NULL);
    cKF_SkeletonInfo_R_play(keyframe);

    if (ftr_actor->switch_bit == TRUE) {
        keyframe->frame_control.speed = 1.0f;
        ftr_actor->dynamic_work_f[0] = 1.0f;
    } else {
        keyframe->frame_control.speed = 0.0f;
        ftr_actor->dynamic_work_f[0] = 0.0f;
    }

    ftr_actor->dynamic_work_f[1] = (f32)(min * mTM_SECONDS_IN_MINUTE + sec) / 600.0f;
}

static void fTMN_mv(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data) {
    cKF_SkeletonInfo_R_c* keyframe = &ftr_actor->keyframe;
    f32 target;

    if (ftr_actor->switch_bit == TRUE) {
        target = 1.0f;
    } else {
        target = 0.0f;
    }

    add_calc(&ftr_actor->dynamic_work_f[0], target, 0.3f, 0.3f, 0.0001f);
    keyframe->frame_control.speed = ftr_actor->dynamic_work_f[0] * 0.5f * 2.0f;
    cKF_SkeletonInfo_R_play(keyframe);

    ftr_actor->dynamic_work_f[1] += 1.820444f;
    if (ftr_actor->dynamic_work_f[1] >= USHT_MAX) {
        ftr_actor->dynamic_work_f[1] = 0.0f;
    }
}

static int fTMN_DrawBefore(GAME* game, cKF_SkeletonInfo_R_c* keyframe, int joint_idx, Gfx** joint_shape,
                           u8* joint_flags, void* arg, s_xyz* joint_rot, xyz_t* joint_pos) {
    FTR_ACTOR* ftr_actor = (FTR_ACTOR*)arg;
    GAME_PLAY* play = (GAME_PLAY*)game;

    if (joint_idx == 1) {
        joint_rot->z += (int)ftr_actor->dynamic_work_f[1];
    }

    return TRUE;
}

static int fTMN_DrawAfter(GAME* game, cKF_SkeletonInfo_R_c* keyframe, int joint_idx, Gfx** joint_shape, u8* joint_flags,
                          void* arg, s_xyz* joint_rot, xyz_t* joint_pos) {
    FTR_ACTOR* ftr_actor = (FTR_ACTOR*)arg;
    GAME_PLAY* play = (GAME_PLAY*)game;

    return TRUE;
}

static void fTMN_dw(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data) {
    GAME_PLAY* play = (GAME_PLAY*)game;
    cKF_SkeletonInfo_R_c* keyframe = &ftr_actor->keyframe;
    Mtx* mtx = ftr_actor->skeleton_mtx[game->frame_counter & 1];

    OPEN_DISP(game->graph);

    gSPMatrix(NEXT_POLY_OPA_DISP, _Matrix_to_Mtx_new(game->graph), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    CLOSE_DISP(game->graph);

    cKF_Si3_draw_R_SV(game, keyframe, mtx, &fTMN_DrawBefore, &fTMN_DrawAfter, ftr_actor);
}

static aFTR_vtable_c fTMN_func = {
    &fTMN_ct, &fTMN_mv, &fTMN_dw, NULL, NULL,
};

aFTR_PROFILE iam_tak_moon = {
    // clang-format off
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	40.0f,
	0.01f,
	aFTR_SHAPE_TYPEC,
	mCoBG_FTR_TYPEC,
	0,
	2,
	0,
	0,
	&fTMN_func,
    // clang-format on
};
