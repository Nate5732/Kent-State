import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { Goal } from './entities/goal.entity';
import { CreateGoalDto } from './dto/create-goal.dto';
import { UpdateGoalDto } from './dto/update-goal.dto';

@Injectable()
export class GoalService {
  constructor(
    @InjectRepository(Goal)
    private goalRepository: Repository<Goal>,
  ) {}

  create(createGoalDto: CreateGoalDto) {
    return this.goalRepository.save(createGoalDto);
  }

  findAllByUserId(userId: number) {
    return this.goalRepository.find({ 
      where: { 
        userId: userId 
      }
    });
  }

  async findOne(id: number) {
    return this.goalRepository.findOne({ 
      where: { id: id } 
    });
  }

  async update(id: number, updateGoalDto: UpdateGoalDto) {
    await this.goalRepository.update(id, updateGoalDto);
    return this.findOne(id);
  }

  async remove(id: number) {
    await this.goalRepository.delete(id);
    return { deleted: true };
  }
}