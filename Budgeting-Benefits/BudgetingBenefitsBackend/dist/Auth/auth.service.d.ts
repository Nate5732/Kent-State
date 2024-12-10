import { JwtService } from '@nestjs/jwt';
import { UserService } from 'src/Models/user/user.service';
export declare class AuthService {
    private jwtService;
    private userService;
    constructor(jwtService: JwtService, userService: UserService);
    validateUser(email: string, password: string): Promise<any>;
    login(user: any): Promise<{
        access_token: string;
        id: any;
    }>;
}
