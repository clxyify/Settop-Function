//First off, update Top/base which can be found in spawn string
//Second off, thanks Acrillus for synX source I got it from here:
int L_BASE = 0;
int L_TOP = 0;
#define r_setnilvalue(obj) ((obj)->tt = NULL)//R_LUA_TNIL is NULL fyi

    void settop(DWORD RState, int idx) const//using 2 arguments because y not
    {
        if (idx >= 0) {//if its greater then or equal to
            while (*(TValue**)(RState + L_TOP) < *(TValue**)(RState + L_BASE) + idx)//add
                r_setnilvalue((*(TValue**)(RState + L_TOP))++);//yep you need this
            *(TValue**)(RState + L_TOP) = *(TValue**)(RState + L_BASE) + idx;
        }
        else
            *(TValue**)(RState + L_TOP) += idx + 1;
    }
